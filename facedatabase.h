#ifndef FACEDATABASE_H
#define FACEDATABASE_H

#include <QWidget>
#include "ui_facedatabase.h"
#include<QSqlQuery>
#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\contrib\contrib.hpp>

//#include<DatabaseConnection.h>

class faceDatabase : public QWidget
{
	Q_OBJECT

public:
	faceDatabase(QWidget *parent = 0);
	~faceDatabase();

	QByteArray faceDatabase::mat2ByteArray(const cv::Mat &image);
	cv::Mat faceDatabase::byteArray2Mat(const QByteArray & byteArray);

private:
	Ui::faceDatabase ui;

	private slots:
	void on_trainButton_pressed();
};

#endif // FACEDATABASE_H
