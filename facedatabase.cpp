#include "facedatabase.h"
#include<QSqlQueryModel>


faceDatabase::faceDatabase(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

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

	QSqlQueryModel *model = new QSqlQueryModel();

	QSqlQuery query;
	query.prepare("select personID, personName,occupation, age, email from personTable");
	
	query.exec();

	model->setQuery(query);

	ui.personTableView->setModel(model);



}

void faceDatabase::on_trainButton_pressed(){
	
	QSqlQuery query;
	query.prepare("select * from imagetable");

	query.exec();


	int id;
	QByteArray returnByteArray;
	cv::Mat retImage;

	std::vector<int> labels;
	std::vector<cv::Mat> images;

	while (query.next()){
		id = query.value(0).toInt();
		returnByteArray = query.value(1).toByteArray();
		retImage = byteArray2Mat(returnByteArray);

		labels.push_back(id);
		images.push_back(retImage);
	}

	cv::Ptr<cv::FaceRecognizer> model;
	model = cv::createEigenFaceRecognizer();
	model->train(images, labels);
	model->save("facerec.yml");
	
	


}

QByteArray faceDatabase::mat2ByteArray(const cv::Mat &image)
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

cv::Mat faceDatabase::byteArray2Mat(const QByteArray & byteArray)
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

faceDatabase::~faceDatabase()
{

}
