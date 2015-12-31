/********************************************************************************
** Form generated from reading UI file 'facedatabase.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEDATABASE_H
#define UI_FACEDATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_faceDatabase
{
public:
    QTableView *personTableView;
    QPushButton *trainButton;

    void setupUi(QWidget *faceDatabase)
    {
        if (faceDatabase->objectName().isEmpty())
            faceDatabase->setObjectName(QStringLiteral("faceDatabase"));
        faceDatabase->resize(874, 750);
        faceDatabase->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        personTableView = new QTableView(faceDatabase);
        personTableView->setObjectName(QStringLiteral("personTableView"));
        personTableView->setGeometry(QRect(90, 60, 671, 431));
        personTableView->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        trainButton = new QPushButton(faceDatabase);
        trainButton->setObjectName(QStringLiteral("trainButton"));
        trainButton->setGeometry(QRect(539, 570, 211, 91));
        trainButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));

        retranslateUi(faceDatabase);

        QMetaObject::connectSlotsByName(faceDatabase);
    } // setupUi

    void retranslateUi(QWidget *faceDatabase)
    {
        faceDatabase->setWindowTitle(QApplication::translate("faceDatabase", "faceDatabase", 0));
        trainButton->setText(QApplication::translate("faceDatabase", "Train Recognizer", 0));
    } // retranslateUi

};

namespace Ui {
    class faceDatabase: public Ui_faceDatabase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEDATABASE_H
