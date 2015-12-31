#ifndef TRAINRECOGNIZER_H
#define TRAINRECOGNIZER_H

#include <QWidget>
#include "ui_trainrecognizer.h"
#include<string.h>
#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\video\video.hpp>
#include<fstream>

using namespace std;
using namespace cv;

class TrainRecognizer : public QWidget
{
	Q_OBJECT

public:
	TrainRecognizer(QWidget *parent = 0);
	~TrainRecognizer();
	void read_csv(const string& , vector<Mat>& , vector<int>& , std::map<int, string>& , char);

	QImage getQImage(cv::Mat &);
	QByteArray mat2ByteArray(const cv::Mat &image);

private:
	Ui::TrainRecognizer ui;

	std::string fileName;

	std::map<int, string> labelsInfo;

	vector<Mat> images;
	vector<int> labels;

	Ptr<FaceRecognizer> model;

	CascadeClassifier faceCascade;
	CascadeClassifier eyeCascade1;
	CascadeClassifier eyeCascade2;

private slots:

	void on_fileButton_pressed();
	void on_trainButton_pressed();
	void on_readButton_pressed();


signals:
	void sendData(vector<Mat> images, vector<int> labels);
};

#endif // TRAINRECOGNIZER_H
