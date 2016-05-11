/********************************************************************************
** Form generated from reading UI file 'trainrecognizer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINRECOGNIZER_H
#define UI_TRAINRECOGNIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainRecognizer
{
public:
    QPushButton *trainButton;
    QToolButton *fileButton;
    QPushButton *readButton;
    QLineEdit *filePathTextEdit;
    QLabel *faceLabel;

    void setupUi(QWidget *TrainRecognizer)
    {
        if (TrainRecognizer->objectName().isEmpty())
            TrainRecognizer->setObjectName(QStringLiteral("TrainRecognizer"));
        TrainRecognizer->resize(797, 590);
        trainButton = new QPushButton(TrainRecognizer);
        trainButton->setObjectName(QStringLiteral("trainButton"));
        trainButton->setGeometry(QRect(630, 490, 151, 91));
        fileButton = new QToolButton(TrainRecognizer);
        fileButton->setObjectName(QStringLiteral("fileButton"));
        fileButton->setGeometry(QRect(550, 400, 25, 19));
        readButton = new QPushButton(TrainRecognizer);
        readButton->setObjectName(QStringLiteral("readButton"));
        readButton->setGeometry(QRect(430, 490, 151, 91));
        filePathTextEdit = new QLineEdit(TrainRecognizer);
        filePathTextEdit->setObjectName(QStringLiteral("filePathTextEdit"));
        filePathTextEdit->setGeometry(QRect(110, 400, 421, 20));
        faceLabel = new QLabel(TrainRecognizer);
        faceLabel->setObjectName(QStringLiteral("faceLabel"));
        faceLabel->setGeometry(QRect(240, 120, 171, 161));

        retranslateUi(TrainRecognizer);

        QMetaObject::connectSlotsByName(TrainRecognizer);
    } // setupUi

    void retranslateUi(QWidget *TrainRecognizer)
    {
        TrainRecognizer->setWindowTitle(QApplication::translate("TrainRecognizer", "TrainRecognizer", 0));
        trainButton->setText(QApplication::translate("TrainRecognizer", "Train Recognizer", 0));
        fileButton->setText(QApplication::translate("TrainRecognizer", "...", 0));
        readButton->setText(QApplication::translate("TrainRecognizer", "Read Face Database", 0));
        faceLabel->setText(QApplication::translate("TrainRecognizer", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TrainRecognizer: public Ui_TrainRecognizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINRECOGNIZER_H
