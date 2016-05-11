/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *titleLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel_5;
    QLabel *nameLabel_12;
    QLabel *nameLabel_6;
    QLabel *nameLabel_7;
    QLabel *nameLabel_8;
    QLabel *nameLabel_9;
    QLabel *nameLabel_10;
    QLabel *nameLabel_13;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *nameLabel_11;
    QLabel *nameLabel_2;
    QLabel *nameLabel_3;
    QLabel *nameLabel_4;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(860, 733);
        About->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        titleLabel = new QLabel(About);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(160, 20, 481, 101));
        titleLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);color: rgb(255, 85, 0);\n"
"font: bold 26pt \"Century Gothic\";"));
        layoutWidget = new QWidget(About);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 250, 2417, 271));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLabel_5 = new QLabel(layoutWidget);
        nameLabel_5->setObjectName(QStringLiteral("nameLabel_5"));
        nameLabel_5->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  8pt \"Century Gothic\";"));

        verticalLayout_2->addWidget(nameLabel_5);

        nameLabel_12 = new QLabel(layoutWidget);
        nameLabel_12->setObjectName(QStringLiteral("nameLabel_12"));
        nameLabel_12->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  12pt \"Century Gothic\";"));

        verticalLayout_2->addWidget(nameLabel_12);

        nameLabel_6 = new QLabel(layoutWidget);
        nameLabel_6->setObjectName(QStringLiteral("nameLabel_6"));
        nameLabel_6->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  12pt \"Century Gothic\";"));

        verticalLayout_2->addWidget(nameLabel_6);

        nameLabel_7 = new QLabel(layoutWidget);
        nameLabel_7->setObjectName(QStringLiteral("nameLabel_7"));
        nameLabel_7->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  12pt \"Century Gothic\";"));

        verticalLayout_2->addWidget(nameLabel_7);

        nameLabel_8 = new QLabel(layoutWidget);
        nameLabel_8->setObjectName(QStringLiteral("nameLabel_8"));
        nameLabel_8->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  12pt \"Century Gothic\";"));

        verticalLayout_2->addWidget(nameLabel_8);

        nameLabel_9 = new QLabel(About);
        nameLabel_9->setObjectName(QStringLiteral("nameLabel_9"));
        nameLabel_9->setGeometry(QRect(450, 510, 481, 111));
        nameLabel_9->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  12pt \"Century Gothic\";"));
        nameLabel_10 = new QLabel(About);
        nameLabel_10->setObjectName(QStringLiteral("nameLabel_10"));
        nameLabel_10->setGeometry(QRect(570, 100, 191, 63));
        nameLabel_10->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  8pt \"Century Gothic\";"));
        nameLabel_13 = new QLabel(About);
        nameLabel_13->setObjectName(QStringLiteral("nameLabel_13"));
        nameLabel_13->setGeometry(QRect(20, 190, 831, 49));
        nameLabel_13->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"font:  8pt \"Century Gothic\";"));
        widget = new QWidget(About);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 250, 169, 271));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 85, 0);\n"
"font: bold 12pt \"Century Gothic\";"));

        verticalLayout->addWidget(nameLabel);

        nameLabel_11 = new QLabel(widget);
        nameLabel_11->setObjectName(QStringLiteral("nameLabel_11"));
        nameLabel_11->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 85, 0);\n"
"font: bold 12pt \"Century Gothic\";"));

        verticalLayout->addWidget(nameLabel_11);

        nameLabel_2 = new QLabel(widget);
        nameLabel_2->setObjectName(QStringLiteral("nameLabel_2"));
        nameLabel_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 85, 0);\n"
"font: bold 12pt \"Century Gothic\";"));

        verticalLayout->addWidget(nameLabel_2);

        nameLabel_3 = new QLabel(widget);
        nameLabel_3->setObjectName(QStringLiteral("nameLabel_3"));
        nameLabel_3->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 85, 0);\n"
"font: bold 12pt \"Century Gothic\";"));

        verticalLayout->addWidget(nameLabel_3);

        nameLabel_4 = new QLabel(widget);
        nameLabel_4->setObjectName(QStringLiteral("nameLabel_4"));
        nameLabel_4->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 85, 0);\n"
"font: bold 12pt \"Century Gothic\";"));

        verticalLayout->addWidget(nameLabel_4);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0));
        titleLabel->setText(QApplication::translate("About", "Face Recognition System", 0));
        nameLabel_5->setText(QApplication::translate("About", "We declare that this thesis is our original work and has not been submitted in any form for another degree or diploma \n"
" at any university or other institute of tertiary education. Information derived from the published and unpublished \n"
" work of others has been acknowledged in the text and a list of references is given.", 0));
        nameLabel_12->setText(QApplication::translate("About", "Face Identification Using Opencv", 0));
        nameLabel_6->setText(QApplication::translate("About", " A.G.M. Zaman ", 0));
        nameLabel_7->setText(QApplication::translate("About", "Our software detects faces. It is also able to recognize the faces using \n"
" Face Recognition algorithm.", 0));
        nameLabel_8->setText(QString());
        nameLabel_9->setText(QApplication::translate("About", "1. Noman Hasan	 13-23545-1\n"
" 2. Islam, Shohidul	13-23461-1\n"
" 3. Akter, Masuma	13-23336-1\n"
" 4. Rafiq, Fatama Binta 13-23447-1\n"
"", 0));
        nameLabel_10->setText(QApplication::translate("About", "2015\n"
"Version 1.2 \n"
"Release Date: 12-21-2015\n"
"", 0));
        nameLabel_13->setText(QApplication::translate("About", "This software is developed as a software project under  A.G.M. Zaman  in American International University of Bangladesh. This software can Detect faces,\n"
" can collect detected faces process them and can save those preprocessed faces into database. Then using Face recognition algorithm this software can \n"
"recognize faces. This feature of this software can be utilized in numerous security and surveillance condition.", 0));
        nameLabel->setText(QApplication::translate("About", "Declaration", 0));
        nameLabel_11->setText(QApplication::translate("About", "Project Name", 0));
        nameLabel_2->setText(QApplication::translate("About", "Project Submitted To : ", 0));
        nameLabel_3->setText(QApplication::translate("About", "Project Summary", 0));
        nameLabel_4->setText(QApplication::translate("About", "Project Members : ", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
