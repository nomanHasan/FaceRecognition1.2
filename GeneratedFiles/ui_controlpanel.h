/********************************************************************************
** Form generated from reading UI file 'controlpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanel
{
public:
    QLabel *loginLabel;
    QLabel *videoFeed;
    QLabel *userLabel;
    QLabel *usernameValue;
    QPushButton *deleteButton;
    QComboBox *selectionComboBox;
    QPushButton *updateButton;
    QPushButton *faceDatabaseButton;
    QPushButton *databaseConfigButton;
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

    void setupUi(QWidget *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QStringLiteral("ControlPanel"));
        ControlPanel->resize(873, 647);
        ControlPanel->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        loginLabel = new QLabel(ControlPanel);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(250, 60, 481, 101));
        loginLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(255, 85, 0);\n"
"font: bold 26pt \"Century Gothic\";"));
        videoFeed = new QLabel(ControlPanel);
        videoFeed->setObjectName(QStringLiteral("videoFeed"));
        videoFeed->setGeometry(QRect(310, 200, 280, 280));
        videoFeed->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        userLabel = new QLabel(ControlPanel);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(580, 20, 81, 35));
        userLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: bold 12pt \"Century Gothic\";"));
        usernameValue = new QLabel(ControlPanel);
        usernameValue->setObjectName(QStringLiteral("usernameValue"));
        usernameValue->setGeometry(QRect(700, 20, 151, 35));
        usernameValue->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(85, 255, 0);\n"
"font: bold 12pt \"Century Gothic\";"));
        deleteButton = new QPushButton(ControlPanel);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(230, 220, 80, 31));
        deleteButton->setStyleSheet(QLatin1String("color: rgb(85, 0, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"font: 75 12pt \"Microsoft YaHei\";\n"
"background-color: rgb(255, 170, 0);\n"
""));
        selectionComboBox = new QComboBox(ControlPanel);
        selectionComboBox->setObjectName(QStringLiteral("selectionComboBox"));
        selectionComboBox->setGeometry(QRect(80, 220, 121, 22));
        selectionComboBox->setStyleSheet(QLatin1String("color: rgb(85, 0, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"font: 75 12pt \"Microsoft YaHei\";\n"
"background-color: rgb(255, 170, 0);\n"
""));
        updateButton = new QPushButton(ControlPanel);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setGeometry(QRect(340, 220, 80, 31));
        updateButton->setStyleSheet(QLatin1String("color: rgb(85, 0, 0);\n"
"border-color: rgba(255, 255, 255, 0);\n"
"font: 75 12pt \"Microsoft YaHei\";\n"
"background-color: rgb(255, 170, 0);\n"
""));
        faceDatabaseButton = new QPushButton(ControlPanel);
        faceDatabaseButton->setObjectName(QStringLiteral("faceDatabaseButton"));
        faceDatabaseButton->setGeometry(QRect(280, 520, 121, 41));
        faceDatabaseButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        databaseConfigButton = new QPushButton(ControlPanel);
        databaseConfigButton->setObjectName(QStringLiteral("databaseConfigButton"));
        databaseConfigButton->setGeometry(QRect(470, 520, 221, 41));
        databaseConfigButton->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei\";color: rgb(85, 0, 0);\n"
"background-color: rgb(255, 170, 0);"));
        layoutWidget = new QWidget(ControlPanel);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 270, 201, 181));
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


        retranslateUi(ControlPanel);

        QMetaObject::connectSlotsByName(ControlPanel);
    } // setupUi

    void retranslateUi(QWidget *ControlPanel)
    {
        ControlPanel->setWindowTitle(QApplication::translate("ControlPanel", "ControlPanel", 0));
        loginLabel->setText(QApplication::translate("ControlPanel", "LOGIN WITH YOUR FACE", 0));
        videoFeed->setText(QApplication::translate("ControlPanel", "TextLabel", 0));
        userLabel->setText(QApplication::translate("ControlPanel", "User :", 0));
        usernameValue->setText(QApplication::translate("ControlPanel", "Name", 0));
        deleteButton->setText(QApplication::translate("ControlPanel", "DELETE", 0));
        updateButton->setText(QApplication::translate("ControlPanel", "UPDATE", 0));
        faceDatabaseButton->setText(QApplication::translate("ControlPanel", "Face Database", 0));
        databaseConfigButton->setText(QApplication::translate("ControlPanel", "Edit Database Configuration", 0));
        nameLabel->setText(QApplication::translate("ControlPanel", "Name", 0));
        occupationLabel->setText(QApplication::translate("ControlPanel", "Occupation", 0));
        ageLabel->setText(QApplication::translate("ControlPanel", "Age", 0));
        emailLabel->setText(QApplication::translate("ControlPanel", "Email", 0));
        nameValue->setText(QApplication::translate("ControlPanel", "Name", 0));
        occupationValue->setText(QApplication::translate("ControlPanel", "Occupation", 0));
        ageValue->setText(QApplication::translate("ControlPanel", "Age", 0));
        emailValue->setText(QApplication::translate("ControlPanel", "Email", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
