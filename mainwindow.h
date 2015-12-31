#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\video\video.hpp>
#include<trainrecognizer.h>
#include<AddPerson.h>
#include<facedatabase.h>
#include<DatabaseConnection.h>
#include<controlpanel.h>
#include<about.h>

using namespace cv;
using namespace std;


class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindowClass ui;
	


	TrainRecognizer * MainWindow::trainer;
	AddPerson * addPerson;
	faceDatabase * fd;
	ControlPanel *cp;
	About *ab;

	CascadeClassifier faceCascade;
	CascadeClassifier eyeCascade1;
	CascadeClassifier eyeCascade2;

	QString status;

	DatabaseConnection db;

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	static QImage getQImage(cv::Mat &timage);
	static void initDetectors(CascadeClassifier &, CascadeClassifier &, CascadeClassifier &);

	Ptr<FaceRecognizer> model;
	


private slots:

	void on_startButton_pressed();
	void on_stopButton_pressed();
	void on_trainFace_pressed();
	void on_addPersonButton_pressed();
	void on_faceDatabaseButton_pressed();
	void on_controlPanelButton_pressed();
	void on_aboutButton_pressed();

public slots:

	void showVideo();
	void recieveDataFromFaceDB(vector<Mat>, vector<int>);
	void recieveDataTraining(vector<Mat>, vector<int>);
	

signals:
	void sendData(vector<Mat> images, vector<int> labels);
};

#endif // MAINWINDOW_H
