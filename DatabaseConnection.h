#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>

class DatabaseConnection{

private:
	QString hostName = "127.0.0.1";
	QString databaseName = "imagedatabase";
	QString userName = "demouser";
	QString userPass = "demopass";

	QSqlDatabase db;

	bool connectionStatus;
	
public:

	DatabaseConnection(){
		db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName(hostName);
		db.setDatabaseName(databaseName);
		db.setUserName(userName);
		db.setPassword(userPass);

		connectionStatus = db.open();
	}

	QSqlQuery getQuery(QString q){
		QSqlQuery query;
		query.prepare(q);
		return query;
	}

	void executeQuery(QString q){
		QSqlQuery query;
		query.prepare(q);
		query.exec();
	}

	bool getConnectionStatus(){
		return connectionStatus;
	}

	~DatabaseConnection(){
		db.close();
	}
};