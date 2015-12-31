#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>
#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\video\video.hpp>
#include "ui_controlpanel.h"

using namespace std;
using namespace cv;

class ControlPanel : public QWidget
{
	Q_OBJECT

public:
	ControlPanel(QWidget *parent = 0);
	~ControlPanel();
	static QImage getQImage(cv::Mat &timage);
	void initDetectors(CascadeClassifier &, CascadeClassifier &, CascadeClassifier &);

	Ptr<FaceRecognizer> model;

	void authorizeLogin();

private:
	Ui::ControlPanel ui;
	CascadeClassifier faceCascade;
	CascadeClassifier eyeCascade1;
	CascadeClassifier eyeCascade2;

	QString status;


	VideoCapture cap;
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

	public slots:

	void showVideo();

};

#endif // CONTROLPANEL_H
