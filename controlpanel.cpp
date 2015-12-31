#include "controlpanel.h"
#include<QTimer>
#include<preprocessFace.h>
#include<recognition.h>
#include<QSqlQuery>
#include<QFileInfo>
#include <ctime>

std::clock_t start;
double duration;

QString currentUser;
int userID;



ControlPanel::ControlPanel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	cap.open(0);

	ui.selectionComboBox->hide();
	ui.faceDatabaseButton->hide();
	ui.databaseConfigButton->hide();
	ui.updateButton->hide();
	ui.deleteButton->hide();

	initDetectors(faceCascade, eyeCascade1, eyeCascade2);

	const int imagePeriod = 1000 / 30;   // ms        
	imageTimer = new QTimer(this);
	imageTimer->setInterval(imagePeriod);
	connect(imageTimer, SIGNAL(timeout()), this, SLOT(showVideo()));

	model = createEigenFaceRecognizer();

	QFileInfo checkFile("facerec.yml");
	if (checkFile.exists()){
		model->load("facerec.yml");
	}

	start = clock();
	imageTimer->start();
}


void ControlPanel::showVideo(){

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
	//ui.videoFeed->resize(ui.videoFeed->pixmap()->size());

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


	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	if (duration>5){
		if (identity > 0){
			currentUser = ui.nameValue->text();
			userID = query.value(0).toInt();

			imageTimer->stop();
			

			//Hiding the video Footage
			ui.videoFeed->hide();
			
			authorizeLogin();
		}
	}

	status += query.value(1).toString() + "  ";

	double confidenceRatio = 1.0 - min(max(similarity, 0.0), 1.0);

	this->update();
}

void  ControlPanel::initDetectors(CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2){

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

QImage ControlPanel::getQImage(cv::Mat &timage){

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

void ControlPanel::authorizeLogin(){

	//Hiding controls
	ui.nameValue->close();
	ui.occupationValue->close();
	ui.ageValue->close();
	ui.emailValue->close();


	ui.nameLabel->close();
	ui.occupationLabel->close();
	ui.ageLabel->close();
	ui.emailLabel->close();

	ui.loginLabel->close();


	//Showing Controls
	ui.selectionComboBox->show();
	ui.faceDatabaseButton->show();
	ui.databaseConfigButton->show();
	ui.updateButton->show();
	ui.deleteButton->show();

	ui.usernameValue->setText(currentUser);
	ui.userLabel->setText("Welcome");
}


ControlPanel::~ControlPanel()
{

}
