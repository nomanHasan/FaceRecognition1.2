/********************************************************************************
** Form generated from reading UI file 'addperson.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSON_H
#define UI_ADDPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPerson
{
public:
    QLabel *footageLabel;
    QLabel *detectedFaceLabel;
    QPushButton *stopButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *occupationLabel;
    QLabel *ageLabel;
    QLabel *emailLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameLineEdit;
    QLineEdit *occupationLineEdit;
    QLineEdit *ageLineEdit;
    QLineEdit *emailLineEdit;
    QPushButton *startButton;
    QLabel *statusLabel;
    QLabel *personIDLabel;
    QLabel *personIDValue;

    void setupUi(QWidget *AddPerson)
    {
        if (AddPerson->objectName().isEmpty())
            AddPerson->setObjectName(QStringLiteral("AddPerson"));
        AddPerson->resize(844, 635);
        AddPerson->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        footageLabel = new QLabel(AddPerson);
        footageLabel->setObjectName(QStringLiteral("footageLabel"));
        footageLabel->setGeometry(QRect(350, 90, 461, 371));
        footageLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        detectedFaceLabel = new QLabel(AddPerson);
        detectedFaceLabel->setObjectName(QStringLiteral("detectedFaceLabel"));
        detectedFaceLabel->setGeometry(QRect(60, 20, 140, 140));
        detectedFaceLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));
        stopButton = new QPushButton(AddPerson);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(50, 510, 251, 81));
        stopButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";\n"
"color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        layoutWidget = new QWidget(AddPerson);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 200, 201, 181));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(nameLabel);

        occupationLabel = new QLabel(layoutWidget);
        occupationLabel->setObjectName(QStringLiteral("occupationLabel"));
        occupationLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(occupationLabel);

        ageLabel = new QLabel(layoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));
        ageLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(ageLabel);

        emailLabel = new QLabel(layoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(emailLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(nameLineEdit);

        occupationLineEdit = new QLineEdit(layoutWidget);
        occupationLineEdit->setObjectName(QStringLiteral("occupationLineEdit"));
        occupationLineEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(occupationLineEdit);

        ageLineEdit = new QLineEdit(layoutWidget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));
        ageLineEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(ageLineEdit);

        emailLineEdit = new QLineEdit(layoutWidget);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));
        emailLineEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(emailLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        startButton = new QPushButton(AddPerson);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(50, 410, 251, 81));
        startButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";\n"
"color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        statusLabel = new QLabel(AddPerson);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(360, 510, 441, 61));
        statusLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));
        personIDLabel = new QLabel(AddPerson);
        personIDLabel->setObjectName(QStringLiteral("personIDLabel"));
        personIDLabel->setGeometry(QRect(70, 140, 54, 40));
        personIDLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));
        personIDValue = new QLabel(AddPerson);
        personIDValue->setObjectName(QStringLiteral("personIDValue"));
        personIDValue->setGeometry(QRect(160, 140, 54, 40));
        personIDValue->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));

        retranslateUi(AddPerson);

        QMetaObject::connectSlotsByName(AddPerson);
    } // setupUi

    void retranslateUi(QWidget *AddPerson)
    {
        AddPerson->setWindowTitle(QApplication::translate("AddPerson", "AddPerson", 0));
        footageLabel->setText(QApplication::translate("AddPerson", "TextLabel", 0));
        detectedFaceLabel->setText(QApplication::translate("AddPerson", "IMAGE", 0));
        stopButton->setText(QApplication::translate("AddPerson", "Stop Training and Add Person", 0));
        nameLabel->setText(QApplication::translate("AddPerson", "Name", 0));
        occupationLabel->setText(QApplication::translate("AddPerson", "Occupation", 0));
        ageLabel->setText(QApplication::translate("AddPerson", "Age", 0));
        emailLabel->setText(QApplication::translate("AddPerson", "Email", 0));
        nameLineEdit->setText(QApplication::translate("AddPerson", "Insert the Name", 0));
        occupationLineEdit->setText(QApplication::translate("AddPerson", "Insert the Occupation", 0));
        ageLineEdit->setText(QApplication::translate("AddPerson", "Insert the persons Age", 0));
        emailLineEdit->setText(QApplication::translate("AddPerson", "Insert the Email", 0));
        startButton->setText(QApplication::translate("AddPerson", "Start", 0));
        statusLabel->setText(QApplication::translate("AddPerson", "TextLabel", 0));
        personIDLabel->setText(QApplication::translate("AddPerson", "Person ID", 0));
        personIDValue->setText(QApplication::translate("AddPerson", "Current ID", 0));
    } // retranslateUi

};

namespace Ui {
    class AddPerson: public Ui_AddPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSON_H
