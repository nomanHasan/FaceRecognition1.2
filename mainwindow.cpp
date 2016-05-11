#include "mainwindow.h"
#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\video\video.hpp>
#include<opencv2\contrib\contrib.hpp>
#include<QPixmap>
#include<Qtcore>
#include<preprocessFace.h>
#include"trainrecognizer.h"
#include <QSqlDatabase>
#include<recognition.h>


using namespace std;
using namespace cv;


VideoCapture cap(0);
QTimer *imageTimer;
Mat cameraFrame;


const char *faceCascadeFilename = "lbpcascade_frontalface.xml";     
const char *eyeCascadeFilename1 = "haarcascade_eye.xml";               
const char *eyeCascadeFilename2 = "haarcascade_eye_tree_eyeglasses.xml";  


const int faceWidth = 70;
const int faceHeight = faceWidth;

const int DESIRED_CAMERA_WIDTH = 640;
const int DESIRED_CAMERA_HEIGHT = 480;

const float UNKNOWN_PERSON_THRESHOLD = 0.4f;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle("Face Recognition System");

	model = createEigenFaceRecognizer();
	

	const int imagePeriod = 1000 / 30;   // ms        
	imageTimer = new QTimer(this);
	imageTimer->setInterval(imagePeriod);
	connect(imageTimer, SIGNAL(timeout()), this, SLOT(showVideo()));

	trainer = new TrainRecognizer();
	connect(trainer, SIGNAL(sendData(vector<Mat>, vector<int>)), this, SLOT(recieveDataFromFaceDB(vector<Mat>, vector<int>)));

	status = " ";
	
	// Load the face and 1 or 2 eye detection XML classifiers.
	initDetectors(faceCascade, eyeCascade1, eyeCascade2);

	//setStyleSheet("background-image: url(Images/sn.jpg);");
	//ui.trainFace->setStyleSheet("QPushButton{background: transparent;}");

	QString st = QString(
		"QProgressBar::chunk {"
		"background-color: #05B8CC;"
		"width: 20px;"
		"}");

	st.append("QProgressBar {"
		" border: 2px solid grey;"
		"border-radius: 5px;"
		"text-align: center;"
		"background-color: #FF0000;"
		"}");
	ui.progressBar->setStyleSheet(st);

}

MainWindow::~MainWindow()
{
	
}

QImage MainWindow::getQImage(cv::Mat &timage){

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

void MainWindow::on_startButton_pressed(){

	if (cap.isOpened()){
		ui.statusLabel->setText(" The Feed is opened");
	}
	else{
		ui.statusLabel->setText("The feed could not be opened");
	}

	QFileInfo checkFile("facerec.yml");
	if (checkFile.exists()){
		model->load("facerec.yml");
	}
	imageTimer->start();	
}

void MainWindow::showVideo(){

	cap.read(cameraFrame);

	//Initializing Cascades


	//ANalyzing the Frame

	Mat displayedFrame;
	cameraFrame.copyTo(displayedFrame);

	int identity = -1;

	
	Rect faceRect;  
	Rect searchedLeftEye, searchedRightEye; 
	Point leftEye, rightEye;  
	Mat preprocessedFace = getPreprocessedFace(displayedFrame, faceWidth, faceCascade, eyeCascade1, eyeCascade2, true, &faceRect, &leftEye, &rightEye, &searchedLeftEye, &searchedRightEye);

	bool gotFaceAndEyes = false;
	if (preprocessedFace.data)
		gotFaceAndEyes = true;

	if (faceRect.width > 0) {
		rectangle(displayedFrame, faceRect, CV_RGB(255, 255, 0), 2, CV_AA);

		// Draw light-blue anti-aliased circles for the 2 eyes.
		Scalar eyeColor = CV_RGB(0, 255, 255);
		if (leftEye.x >= 0) {   // Check if the eye was detected
			circle(displayedFrame, Point(faceRect.x + leftEye.x, faceRect.y + leftEye.y), 6, eyeColor, 1, CV_AA);
		}
		if (rightEye.x >= 0) {   // Check if the eye was detected
			circle(displayedFrame, Point(faceRect.x + rightEye.x, faceRect.y + rightEye.y), 6, eyeColor, 1, CV_AA);
		}
	}

	Mat reconstructedFace;
	reconstructedFace = reconstructFace(model, preprocessedFace);

	double similarity = getSimilarity(preprocessedFace, reconstructedFace);

	QString outputStr;
	if (similarity < UNKNOWN_PERSON_THRESHOLD) {
		// Identify who the person is in the preprocessed face image.
		identity = model->predict(preprocessedFace);
		outputStr = QString::number(identity);
	}
	else {
		outputStr = "Unknown";
	}

	status = "Identity: " + QString::number(identity) + " Final Identity: " + outputStr;

	

	ui.videoFeed->setScaledContents(true);
	ui.videoFeed->setPixmap(QPixmap::fromImage(getQImage(displayedFrame)));
	ui.videoFeed->resize(ui.videoFeed->pixmap()->size());

	ui.detectedFace->setScaledContents(true);
	ui.detectedFace->setPixmap(QPixmap::fromImage(getQImage(preprocessedFace)));
	ui.detectedFace->resize(ui.detectedFace->pixmap()->size());

	ui.faceLabel->setScaledContents(true);
	ui.faceLabel->setPixmap(QPixmap::fromImage(getQImage(reconstructedFace)));
	ui.faceLabel->resize(ui.faceLabel->pixmap()->size());



	QSqlQuery query;
	query.prepare("select * from personTable where personID = :id");
	query.bindValue(":id", identity);
	query.exec();
	

	while (query.next()){
		QString name = query.value(1).toString();
		QString occupation = query.value(2).toString();
		QString age = query.value(3).toString();
		QString email = query.value(4).toString();

		ui.nameValue->setText(name);
		ui.occupationValue->setText(occupation);
		ui.ageValue->setText(age);
		ui.emailValue->setText(email);
	}

	if (identity < 0){
		ui.nameValue->setText("UNKNOWN");
		ui.occupationValue->setText("UNKNOWN");
		ui.ageValue->setText("UNKNOWN");
		ui.emailValue->setText("UNKNOWN");
	}
	
	status += query.value(1).toString()+"  ";

	double confidenceRatio = 1.0 - min(max(similarity, 0.0), 1.0);

	ui.progressBar->setValue(confidenceRatio);
	if (db.getConnectionStatus()){
		status += "Connection OK";
	}


	ui.statusLabel->setText(status);
	this->update(); 
}

void MainWindow::on_stopButton_pressed(){
	imageTimer->stop();
}

void MainWindow::on_trainFace_pressed(){
	
	trainer->show();
}

void  MainWindow::initDetectors(CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2){

	try {
		faceCascade.load(faceCascadeFilename);
	}
	catch (cv::Exception &e) {

	}

	try {
		eyeCascade1.load(eyeCascadeFilename1);
	}
	catch (cv::Exception &e) {

	}

	try {
		eyeCascade2.load(eyeCascadeFilename2);
	}
	catch (cv::Exception &e) {

	}

}


void MainWindow::recieveDataFromFaceDB(vector<Mat> images, vector<int> labels){
	ui.statusLabel->setText("Face Database read to the memory");

	Mat testSample = images[images.size() - 1];
	int nlabels = (int)labels.size();
	int testLabel = labels[nlabels - 1];
	images.pop_back();
	labels.pop_back();

	model = createEigenFaceRecognizer();
	for (int i = 0; i < nlabels; i++)
		
	model->train(images, labels);
	string saveModelPath = "face-rec-model.txt";
	cout << "Saving the trained model to " << saveModelPath << endl;
	model->save(saveModelPath);
}

void MainWindow::recieveDataTraining(vector<Mat> images, vector<int> labels){
	ui.statusLabel->setText("Face Database read to the memory");

	Mat testSample = images[images.size() - 1];
	int nlabels = (int)labels.size();
	int testLabel = labels[nlabels - 1];
	images.pop_back();
	labels.pop_back();

	
	
}

void MainWindow::on_controlPanelButton_pressed(){
	cp = new ControlPanel();
	cp->show();
}

void MainWindow::on_addPersonButton_pressed(){

	imageTimer->stop();

	addPerson = new AddPerson();
	connect(addPerson, SIGNAL(sendData(vector<Mat>, vector<int>)), this, SLOT(recieveDataTraining(vector<Mat>, vector<int>)));

	addPerson->show();
}

void MainWindow::on_aboutButton_pressed(){
	ab = new About();
	ab->show();
}

void MainWindow::on_faceDatabaseButton_pressed(){

	fd = new faceDatabase();
	fd->show();

}