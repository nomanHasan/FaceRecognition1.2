#include "addperson.h"
#include<preprocessFace.h>
#include<mainwindow.h>
#include<recognition.h>



const int DESIRED_CAMERA_WIDTH = 640;
const int DESIRED_CAMERA_HEIGHT = 480;

const double CHANGE_IN_IMAGE_FOR_COLLECTION = 0.3;    
const double CHANGE_IN_SECONDS_FOR_COLLECTION = 1.0;

Mat old_prepreprocessedFace;

const int faceWidth = 70;


double old_time = 0.0;

AddPerson::AddPerson(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	model = createEigenFaceRecognizer();
	//model->load("face-rec-model.txt");

	//Databse Connection Establishment

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

	if (ok){
		ui.statusLabel->setText("Database Connection was opened");
	}
	else{
		ui.statusLabel->setText("Database connection could not be opened");
	}

	QString status;


	//Getting the Current PersonID

	QSqlQuery query;
	query.exec("select max(personID) from imageTable");

	if (query.next()){
		if (query.value(0).toString()>=0){
			currentPersonID = query.value(0).toInt() + 1;
			status = "The query returned Value  ";
		}
		else{
			currentPersonID = 0;
			status = "the Query  returned NULL";
		}
	}


	status += " DataTable Size: " + QString::number(query.size());

	status += "the Value is : " + QString::number(query.value(0).toInt());

	status += "CurrentPersonID: " + QString::number(currentPersonID);

	ui.personIDValue->setText(QString::number(currentPersonID));

	//Openning the image
	//Mat image = imread("m.jpg",CV_8UC3);
	//QByteArray imageByteArray = mat2ByteArray(image);


	////ui.footageLabel->setScaledContents(true);
	////ui.footageLabel->setPixmap(QPixmap::fromImage(getQImage(image)));
	//////ui.footageLabel->resize(ui.footageLabel->pixmap()->size());

	//
	//query.prepare("INSERT INTO personTable (personID, personName, occupation, age, email, image) "
	//	"VALUES (:id, :name, :occupation, :age, :email, :image)");
	//query.bindValue(":id", 0);
	//query.bindValue(":name", "Noman Hasan");
	//query.bindValue(":occupation", "Student");
	//query.bindValue(":age", 21);
	//query.bindValue(":email", "nomanbinhussein@gmail.com");
	//query.bindValue(":image", imageByteArray);
	//query.exec();

	//QSqlQuery query2;
	//query2.exec("SELECT * from personTable");

	//QString name, occupation, email;
	//int age;
	//QByteArray returnByteArray;

	//while (query2.next()){
	//	name = query2.value(1).toString();
	//	occupation = query2.value(2).toString();
	//	age = query2.value(3).toInt();
	//	email = query2.value(4).toString();
	//	returnByteArray = query2.value(5).toByteArray();
	//}
	//
	//Mat retImage = byteArray2Mat(returnByteArray);

	//

	////cv::imshow("retImage", retImage);

	//ui.nameLineEdit->setText(name);
	//ui.occupationLineEdit->setText(occupation);
	//ui.ageLineEdit->setText(QString::number(age));
	//ui.emailLineEdit->setText(email);
/*
	ui.detectedFaceLabel->setScaledContents(true);
	ui.detectedFaceLabel->setPixmap(QPixmap::fromImage(getQImage(retImage)));*/
	//ui.detectedFaceLabel->resize(ui.detectedFaceLabel->pixmap()->size());

	ui.statusLabel->setText(status);

	//Actual Footage 
	cap.open(0);
	const int imagePeriod = 1000 / 30;
	imageTimer = new QTimer(this);
	imageTimer->setInterval(imagePeriod);
	connect(imageTimer, SIGNAL(timeout()), this, SLOT(showVideo()));
	

	MainWindow::initDetectors(faceCascade, eyeCascade1, eyeCascade2);


}


void AddPerson::showVideo(){

	
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

	Mat capturedFace;

	if (gotFaceAndEyes) {

		// Check if this face looks somewhat different from the previously collected face.
		double imageDiff = 10000000000.0;
		if (old_prepreprocessedFace.data) {
			imageDiff = getSimilarity(preprocessedFace, old_prepreprocessedFace);
		}

		// Also record when it happened.
		double current_time = (double)getTickCount();
		double timeDiff_seconds = (current_time - old_time) / getTickFrequency();

		// Only process the face if it is noticeably different from the previous frame and there has been noticeable time gap.
		if ((imageDiff > CHANGE_IN_IMAGE_FOR_COLLECTION) && (timeDiff_seconds > CHANGE_IN_SECONDS_FOR_COLLECTION)) {
			// Also add the mirror image to the training set, so we have more training data, as well as to deal with faces looking to the left or right.
			Mat mirroredFace;
			flip(preprocessedFace, mirroredFace, 1);

			// Add the face images to the list of detected faces.
			preprocessedFaces.push_back(preprocessedFace);
			preprocessedFaces.push_back(mirroredFace);
			faceLabels.push_back(currentPersonID);
			faceLabels.push_back(currentPersonID);

			// Make a white flash on the face, so the user knows a photo has been taken.
			Mat displayedFaceRegion = displayedFrame(faceRect);
			displayedFaceRegion += CV_RGB(90, 90, 90);

			// Keep a copy of the processed face, to compare on next iteration.
			old_prepreprocessedFace = preprocessedFace;
			old_time = current_time;

			capturedFace = preprocessedFace;
		}
	}


	ui.footageLabel->setScaledContents(true);
	ui.footageLabel->setPixmap(QPixmap::fromImage(getQImage(displayedFrame)));
	ui.footageLabel->resize(ui.footageLabel->pixmap()->size());

	ui.detectedFaceLabel->setScaledContents(true);
	ui.detectedFaceLabel->setPixmap(QPixmap::fromImage(getQImage(capturedFace)));
	ui.detectedFaceLabel->resize(ui.detectedFaceLabel->pixmap()->size());

	this->update();
}



QByteArray AddPerson::mat2ByteArray(const cv::Mat &image)
{
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

 cv::Mat AddPerson::byteArray2Mat(const QByteArray & byteArray)
 {
	 QDataStream stream(byteArray);
	 int matType, rows, cols;
	 QByteArray data;
	 stream >> matType;
	 stream >> rows;
	 stream >> cols;
	 stream >> data;
	 cv::Mat mat(rows, cols, matType, (void*)data.data());
	 return mat.clone();
 }


QImage AddPerson::getQImage(cv::Mat &timage){

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

void AddPerson::on_startButton_pressed(){
	imageTimer->start();
}

void AddPerson::on_stopButton_pressed(){
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
	
	QString name, occupation, email;
	int age, personID;
	QByteArray returnByteArray;


	personID = currentPersonID;
	name = ui.nameLineEdit->text();
	occupation = ui.occupationLineEdit->text();
	email = ui.emailLineEdit->text();
	age = ui.ageLineEdit->text().toInt();

	//Inserting into personTable Database

	Mat faceImage = preprocessedFaces[0];
	QByteArray faceImageByteArray = mat2ByteArray(faceImage);

	QSqlQuery query;
	query.prepare("INSERT INTO personTable (personID, personName, occupation, age, email, image) "
		"VALUES (:id, :name, :occupation, :age, :email, :image)");
	query.bindValue(":id", personID);
	query.bindValue(":name", name);
	query.bindValue(":occupation", occupation);
	query.bindValue(":age", age);
	query.bindValue(":email", email);
	query.bindValue(":image", faceImageByteArray);
	query.exec();


	//Inserting into imagetable Table
	for (int i = 0; i < preprocessedFaces.size(); i++){
		query.prepare("INSERT INTO imageTable (personID, image) "
			"VALUES (:id, :image)");
		query.bindValue(":id", faceLabels[i]);
		query.bindValue(":image", mat2ByteArray(preprocessedFaces[i]));
		query.exec();
	}

	//Training the Face Recognition algorithm

	model->load("facerec.yml");
	model->train(preprocessedFaces, faceLabels);
	model->save("facerec.yml");

	this->close();
}

AddPerson::~AddPerson()
{

}
