/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *videoFeed;
    QLabel *detectedFace;
    QLabel *faceLabel;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *trainFace;
    QPushButton *faceDatabaseButton;
    QPushButton *addPersonButton;
    QPushButton *controlPanelButton;
    QPushButton *aboutButton;
    QLabel *statusLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *occupationLabel;
    QLabel *ageLabel;
    QLabel *emailLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameValue;
    QLabel *occupationValue;
    QLabel *ageValue;
    QLabel *emailValue;
    QLabel *personImage;
    QProgressBar *progressBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(909, 654);
        MainWindowClass->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        videoFeed = new QLabel(centralWidget);
        videoFeed->setObjectName(QStringLiteral("videoFeed"));
        videoFeed->setGeometry(QRect(250, 30, 601, 481));
        videoFeed->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        detectedFace = new QLabel(centralWidget);
        detectedFace->setObjectName(QStringLiteral("detectedFace"));
        detectedFace->setGeometry(QRect(10, 30, 70, 70));
        detectedFace->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));
        faceLabel = new QLabel(centralWidget);
        faceLabel->setObjectName(QStringLiteral("faceLabel"));
        faceLabel->setGeometry(QRect(110, 30, 70, 70));
        faceLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);font: 12pt \"Microsoft YaHei\";color: rgb(255, 255, 255);"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(10, 570, 80, 41));
        startButton->setStyleSheet(QLatin1String("color: rgb(85, 0, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"font: 75 12pt \"Microsoft YaHei\";\n"
"background-color: rgb(255, 170, 0);\n"
""));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(120, 570, 80, 41));
        stopButton->setStyleSheet(QLatin1String("font: 75 12pt \"Microsoft YaHei\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        trainFace = new QPushButton(centralWidget);
        trainFace->setObjectName(QStringLiteral("trainFace"));
        trainFace->setGeometry(QRect(230, 570, 121, 41));
        trainFace->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        faceDatabaseButton = new QPushButton(centralWidget);
        faceDatabaseButton->setObjectName(QStringLiteral("faceDatabaseButton"));
        faceDatabaseButton->setGeometry(QRect(410, 570, 121, 41));
        faceDatabaseButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        addPersonButton = new QPushButton(centralWidget);
        addPersonButton->setObjectName(QStringLiteral("addPersonButton"));
        addPersonButton->setGeometry(QRect(10, 470, 91, 41));
        addPersonButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        controlPanelButton = new QPushButton(centralWidget);
        controlPanelButton->setObjectName(QStringLiteral("controlPanelButton"));
        controlPanelButton->setGeometry(QRect(579, 570, 121, 41));
        controlPanelButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        aboutButton = new QPushButton(centralWidget);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setGeometry(QRect(730, 570, 80, 41));
        aboutButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(350, 540, 301, 16));
        statusLabel->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);font: 10pt \"Microsoft YaHei\";color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 260, 201, 181));
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
        nameLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout->addWidget(nameLabel);

        occupationLabel = new QLabel(layoutWidget);
        occupationLabel->setObjectName(QStringLiteral("occupationLabel"));
        occupationLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout->addWidget(occupationLabel);

        ageLabel = new QLabel(layoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));
        ageLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout->addWidget(ageLabel);

        emailLabel = new QLabel(layoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout->addWidget(emailLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nameValue = new QLabel(layoutWidget);
        nameValue->setObjectName(QStringLiteral("nameValue"));
        nameValue->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout_2->addWidget(nameValue);

        occupationValue = new QLabel(layoutWidget);
        occupationValue->setObjectName(QStringLiteral("occupationValue"));
        occupationValue->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout_2->addWidget(occupationValue);

        ageValue = new QLabel(layoutWidget);
        ageValue->setObjectName(QStringLiteral("ageValue"));
        ageValue->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout_2->addWidget(ageValue);

        emailValue = new QLabel(layoutWidget);
        emailValue->setObjectName(QStringLiteral("emailValue"));
        emailValue->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: 10pt \"Lucida Console\";"));

        verticalLayout_2->addWidget(emailValue);


        horizontalLayout->addLayout(verticalLayout_2);

        personImage = new QLabel(centralWidget);
        personImage->setObjectName(QStringLiteral("personImage"));
        personImage->setGeometry(QRect(10, 110, 140, 140));
        personImage->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);color: rgb(255, 255, 255);"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(160, 130, 16, 121));
        progressBar->setStyleSheet(QStringLiteral(""));
        progressBar->setValue(24);
        progressBar->setOrientation(Qt::Vertical);
        MainWindowClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        videoFeed->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
        detectedFace->setText(QString());
        faceLabel->setText(QString());
        startButton->setText(QApplication::translate("MainWindowClass", "START", 0));
        stopButton->setText(QApplication::translate("MainWindowClass", "STOP", 0));
        trainFace->setText(QApplication::translate("MainWindowClass", "Train from CSV", 0));
        faceDatabaseButton->setText(QApplication::translate("MainWindowClass", "Face Database", 0));
        addPersonButton->setText(QApplication::translate("MainWindowClass", "Add Person", 0));
        controlPanelButton->setText(QApplication::translate("MainWindowClass", "Control Panel", 0));
        aboutButton->setText(QApplication::translate("MainWindowClass", "About", 0));
        statusLabel->setText(QString());
        nameLabel->setText(QApplication::translate("MainWindowClass", "Name", 0));
        occupationLabel->setText(QApplication::translate("MainWindowClass", "Occupation", 0));
        ageLabel->setText(QApplication::translate("MainWindowClass", "Age", 0));
        emailLabel->setText(QApplication::translate("MainWindowClass", "Email", 0));
        nameValue->setText(QApplication::translate("MainWindowClass", "Name", 0));
        occupationValue->setText(QApplication::translate("MainWindowClass", "Occupation", 0));
        ageValue->setText(QApplication::translate("MainWindowClass", "Age", 0));
        emailValue->setText(QApplication::translate("MainWindowClass", "Email", 0));
        personImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
