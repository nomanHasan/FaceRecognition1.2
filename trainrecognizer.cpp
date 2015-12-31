#include "trainrecognizer.h"
#include"qfiledialog.h"
#include"QString"
#include"QFileDialog.h"
#include"QVBoxLayout"
#include<QLabel>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<mainwindow.h>
#include<preprocessFace.h>

const int faceWidth = 70;

TrainRecognizer::TrainRecognizer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	MainWindow::initDetectors(faceCascade, eyeCascade1, eyeCascade2);
	
}

TrainRecognizer::~TrainRecognizer()
{

}

void TrainRecognizer::read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, std::map<int, string>& labelsInfo, char separator = ';') {
	ifstream csv(filename.c_str());
	if (!csv) cerr << "No valid input file was given, please check the given filename.";
	string line, path, classlabel, info;
	while (getline(csv, line)) {
		stringstream liness(line);
		path.clear(); classlabel.clear(); info.clear();
		getline(liness, path, separator);
		getline(liness, classlabel, separator);
		getline(liness, info, separator);
		if (!path.empty() && !classlabel.empty()) {
			cout << "Processing " << path << endl;
			int label = atoi(classlabel.c_str());
			if (!info.empty())
				labelsInfo.insert(std::make_pair(label, info));
			// 'path' can be file, dir or wildcard path
			String root(path.c_str());
			vector<String> files;
			glob(root, files, true);
			for (vector<String>::const_iterator f = files.begin(); f != files.end(); ++f) {
				cout << "\t" << *f << endl;
				Mat img = imread(*f, IMREAD_GRAYSCALE);
				static int w = -1, h = -1;
				static bool showSmallSizeWarning = true;
				if (w>0 && h>0 && (w != img.cols || h != img.rows)) cout << "\t*!" << endl;
				if (showSmallSizeWarning && (img.cols<50 || img.rows<50)) {
					cout << "*" << endl;
					showSmallSizeWarning = false;
				}
				images.push_back(img);
				labels.push_back(label);
			}
		}
	}
}

void TrainRecognizer::on_fileButton_pressed(){
	QString qFileName = QFileDialog::getOpenFileName(this,
		tr("Open CSV File"), ".",
		tr("Image Files (*.txt)"));

	fileName = qFileName.toLatin1().data();
	ui.filePathTextEdit->setText(qFileName);
}

void TrainRecognizer::on_readButton_pressed(){
	//fileName = "C:\\Users\no\Google Drive\Visual Studio 2013\Projects\FaceRecognition1.0\FaceDatabase\at.txt";
	read_csv(fileName, images, labels, labelsInfo, ';');

	QHBoxLayout *layout = new QHBoxLayout();
	for (Mat image : images){
		QLabel *label = new QLabel();
		label->setPixmap(QPixmap::fromImage(getQImage(image)));
		label->resize(label->pixmap()->size());
		layout->addWidget(label);
	}


	//setLayout(layout);
}

void TrainRecognizer::on_trainButton_pressed(){


	QString hostName = "127.0.0.1";
	QString databaseName = "imagedatabase";
	QString userName = "demouser";
	QString userPass = "demopass";

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(hostName);
	db.setDatabaseName(databaseName);
	db.setUserName(userName);
	db.setPassword(userPass);

	bool ok = db.open();

	Mat testSample = images[images.size() - 1];
	int nlabels = (int)labels.size();
	int testLabel = labels[nlabels - 1];
	images.pop_back();
	labels.pop_back();

	QSqlQuery query;

	query.prepare("INSERT INTO imageTable (personID, image) "
		"VALUES (:id, :image)");
	Rect faceRect;
	Rect searchedLeftEye, searchedRightEye;
	Point leftEye, rightEye;
	ui.faceLabel->setScaledContents(true);
	ui.faceLabel->setPixmap(QPixmap::fromImage(getQImage(images[10])));
	ui.faceLabel->resize(ui.faceLabel->pixmap()->size());

	for (int i = 0; i < images.size(); i++){
		
		Mat image = images[i];
		Mat preprocessedFace = getPreprocessedFace(image, faceWidth, faceCascade, eyeCascade1, eyeCascade2, true, &faceRect, &leftEye, &rightEye, &searchedLeftEye, &searchedRightEye);

		if (preprocessedFace.data){
			query.bindValue(":id", labels[i]);
			query.bindValue(":image", mat2ByteArray(preprocessedFace));
			query.exec();
		}		
	}
	
	model = createEigenFaceRecognizer();
	//model->load("facerec.yml");
	model->train(images, labels);
	model->save("facerec.yml");
	
	//this->close();
}


QByteArray TrainRecognizer::mat2ByteArray(const cv::Mat &image){

	QByteArray byteArray;
	QDataStream stream(&byteArray, QIODevice::WriteOnly);
	stream << image.type();
	stream << image.rows;
	stream << image.cols;
	const size_t data_size = image.cols * image.rows * image.elemSize();
	QByteArray data = QByteArray::fromRawData((const char*)image.ptr(), data_size);
	stream << data;
	return byteArray;
}


QImage TrainRecognizer::getQImage(cv::Mat &timage){

	static QVector<QRgb> colorTable;

	if (colorTable.isEmpty()){
		for (int i = 0; i < 256; i++){
			colorTable.push_back(qRgb(i, i, i));
		}
	}

	if (timage.type() == CV_8UC3){
		QImage temp = QImage((const unsigned char*)(timage.data), timage.cols, timage.rows, timage.step, QImage::Format_RGB888);
		return temp.rgbSwapped();
	}
	else if (timage.type() == CV_8UC1){
		QImage temp = QImage((const unsigned char*)(timage.data), timage.cols, timage.rows, timage.step, QImage::Format_Indexed8);
		temp.setColorTable(colorTable);
		return temp;
	}
}