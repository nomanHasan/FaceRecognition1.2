#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QWidget>
#include "ui_addperson.h"
#include <QWidget>
#include<string.h>
#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\video\video.hpp>
#include<fstream>
#include <QSqlDatabase>
#include<QTimer>
#include<QSqlQuery>

using namespace std;
using namespace cv;

class AddPerson : public QWidget
{
	Q_OBJECT

public:
	AddPerson(QWidget *parent = 0);
	~AddPerson();
	QByteArray AddPerson::mat2ByteArray(const cv::Mat &image);
	cv::Mat AddPerson::byteArray2Mat(const QByteArray & byteArray);

	QImage AddPerson::getQImage(cv::Mat &timage);

private:

	Ui::AddPerson ui;


	VideoCapture cap;
	QTimer *imageTimer;
	Mat cameraFrame;

	CascadeClassifier faceCascade;
	CascadeClassifier eyeCascade1;
	CascadeClassifier eyeCascade2;

	vector<Mat> preprocessedFaces;
	vector<int> faceLabels;

	int currentPersonID;

	Ptr<FaceRecognizer> model;


	private slots:
	void on_startButton_pressed();
	void on_stopButton_pressed();
	void showVideo();

signals:
	void sendData(vector<Mat> images, vector<int> labels);
};

#endif // ADDPERSON_H
