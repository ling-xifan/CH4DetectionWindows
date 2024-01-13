/********************************************************************************
** Form generated from reading UI file 'humidity.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUMIDITY_H
#define UI_HUMIDITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_humidity
{
public:
    QPushButton *pushSendMinY;
    QLabel *label_3;
    QLabel *label_8;
    QLineEdit *lineminY;
    QLabel *label_5;
    QPushButton *pushSendMinX;
    QPushButton *pushSendMaxX;
    QPushButton *pushSendMaxY;
    QLabel *label_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *lineminX;
    QLabel *label_7;
    QLineEdit *linemaxY;
    QLineEdit *linemaxX;

    void setupUi(QWidget *humidity)
    {
        if (humidity->objectName().isEmpty())
            humidity->setObjectName(QString::fromUtf8("humidity"));
        humidity->resize(795, 515);
        pushSendMinY = new QPushButton(humidity);
        pushSendMinY->setObjectName(QString::fromUtf8("pushSendMinY"));
        pushSendMinY->setGeometry(QRect(600, 450, 70, 25));
        label_3 = new QLabel(humidity);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 450, 50, 25));
        label_8 = new QLabel(humidity);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 480, 71, 25));
        lineminY = new QLineEdit(humidity);
        lineminY->setObjectName(QString::fromUtf8("lineminY"));
        lineminY->setGeometry(QRect(470, 450, 113, 25));
        label_5 = new QLabel(humidity);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 450, 71, 25));
        pushSendMinX = new QPushButton(humidity);
        pushSendMinX->setObjectName(QString::fromUtf8("pushSendMinX"));
        pushSendMinX->setGeometry(QRect(600, 480, 70, 25));
        pushSendMaxX = new QPushButton(humidity);
        pushSendMaxX->setObjectName(QString::fromUtf8("pushSendMaxX"));
        pushSendMaxX->setGeometry(QRect(310, 480, 70, 25));
        pushSendMaxY = new QPushButton(humidity);
        pushSendMaxY->setObjectName(QString::fromUtf8("pushSendMaxY"));
        pushSendMaxY->setGeometry(QRect(310, 450, 70, 25));
        label_6 = new QLabel(humidity);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 480, 50, 25));
        verticalLayoutWidget = new QWidget(humidity);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 761, 421));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(humidity);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 450, 50, 25));
        lineminX = new QLineEdit(humidity);
        lineminX->setObjectName(QString::fromUtf8("lineminX"));
        lineminX->setGeometry(QRect(470, 480, 113, 25));
        label_7 = new QLabel(humidity);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(410, 480, 50, 25));
        linemaxY = new QLineEdit(humidity);
        linemaxY->setObjectName(QString::fromUtf8("linemaxY"));
        linemaxY->setGeometry(QRect(180, 450, 113, 25));
        linemaxX = new QLineEdit(humidity);
        linemaxX->setObjectName(QString::fromUtf8("linemaxX"));
        linemaxX->setGeometry(QRect(180, 480, 113, 25));

        retranslateUi(humidity);

        QMetaObject::connectSlotsByName(humidity);
    } // setupUi

    void retranslateUi(QWidget *humidity)
    {
        humidity->setWindowTitle(QCoreApplication::translate("humidity", "Form", nullptr));
        pushSendMinY->setText(QCoreApplication::translate("humidity", "\345\217\221\351\200\201", nullptr));
        label_3->setText(QCoreApplication::translate("humidity", "\346\234\200\345\244\247\345\200\274", nullptr));
        label_8->setText(QCoreApplication::translate("humidity", "\346\227\266\351\227\264\350\214\203\345\233\264", nullptr));
        label_5->setText(QCoreApplication::translate("humidity", "\346\271\277\345\272\246\350\214\203\345\233\264", nullptr));
        pushSendMinX->setText(QCoreApplication::translate("humidity", "\345\217\221\351\200\201", nullptr));
        pushSendMaxX->setText(QCoreApplication::translate("humidity", "\345\217\221\351\200\201", nullptr));
        pushSendMaxY->setText(QCoreApplication::translate("humidity", "\345\217\221\351\200\201", nullptr));
        label_6->setText(QCoreApplication::translate("humidity", "\346\234\200\345\244\247\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("humidity", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_7->setText(QCoreApplication::translate("humidity", "\346\234\200\345\260\217\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class humidity: public Ui_humidity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUMIDITY_H
