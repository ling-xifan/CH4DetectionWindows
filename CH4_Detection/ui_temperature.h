/********************************************************************************
** Form generated from reading UI file 'temperature.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPERATURE_H
#define UI_TEMPERATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Temperature
{
public:
    QLineEdit *linemaxY;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *lineminY;
    QLabel *label_7;
    QLabel *label_4;
    QPushButton *pushSendMinX;
    QLineEdit *linemaxX;
    QPushButton *pushSendMinY;
    QLabel *label_6;
    QLabel *label_3;
    QLineEdit *lineminX;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushSendMaxY;
    QPushButton *pushSendMaxX;

    void setupUi(QWidget *Temperature)
    {
        if (Temperature->objectName().isEmpty())
            Temperature->setObjectName(QString::fromUtf8("Temperature"));
        Temperature->resize(801, 540);
        linemaxY = new QLineEdit(Temperature);
        linemaxY->setObjectName(QString::fromUtf8("linemaxY"));
        linemaxY->setGeometry(QRect(180, 460, 113, 25));
        label_5 = new QLabel(Temperature);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 460, 71, 25));
        label_8 = new QLabel(Temperature);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 490, 71, 25));
        lineminY = new QLineEdit(Temperature);
        lineminY->setObjectName(QString::fromUtf8("lineminY"));
        lineminY->setGeometry(QRect(470, 460, 113, 25));
        label_7 = new QLabel(Temperature);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(410, 490, 50, 25));
        label_4 = new QLabel(Temperature);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 460, 50, 25));
        pushSendMinX = new QPushButton(Temperature);
        pushSendMinX->setObjectName(QString::fromUtf8("pushSendMinX"));
        pushSendMinX->setGeometry(QRect(600, 490, 70, 25));
        linemaxX = new QLineEdit(Temperature);
        linemaxX->setObjectName(QString::fromUtf8("linemaxX"));
        linemaxX->setGeometry(QRect(180, 490, 113, 25));
        pushSendMinY = new QPushButton(Temperature);
        pushSendMinY->setObjectName(QString::fromUtf8("pushSendMinY"));
        pushSendMinY->setGeometry(QRect(600, 460, 70, 25));
        label_6 = new QLabel(Temperature);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 490, 50, 25));
        label_3 = new QLabel(Temperature);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 460, 50, 25));
        lineminX = new QLineEdit(Temperature);
        lineminX->setObjectName(QString::fromUtf8("lineminX"));
        lineminX->setGeometry(QRect(470, 490, 113, 25));
        verticalLayoutWidget = new QWidget(Temperature);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 761, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushSendMaxY = new QPushButton(Temperature);
        pushSendMaxY->setObjectName(QString::fromUtf8("pushSendMaxY"));
        pushSendMaxY->setGeometry(QRect(310, 460, 70, 25));
        pushSendMaxX = new QPushButton(Temperature);
        pushSendMaxX->setObjectName(QString::fromUtf8("pushSendMaxX"));
        pushSendMaxX->setGeometry(QRect(310, 490, 70, 25));

        retranslateUi(Temperature);

        QMetaObject::connectSlotsByName(Temperature);
    } // setupUi

    void retranslateUi(QWidget *Temperature)
    {
        Temperature->setWindowTitle(QCoreApplication::translate("Temperature", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Temperature", "\346\270\251\345\272\246\350\214\203\345\233\264", nullptr));
        label_8->setText(QCoreApplication::translate("Temperature", "\346\227\266\351\227\264\350\214\203\345\233\264", nullptr));
        label_7->setText(QCoreApplication::translate("Temperature", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("Temperature", "\346\234\200\345\260\217\345\200\274", nullptr));
        pushSendMinX->setText(QCoreApplication::translate("Temperature", "\345\217\221\351\200\201", nullptr));
        pushSendMinY->setText(QCoreApplication::translate("Temperature", "\345\217\221\351\200\201", nullptr));
        label_6->setText(QCoreApplication::translate("Temperature", "\346\234\200\345\244\247\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("Temperature", "\346\234\200\345\244\247\345\200\274", nullptr));
        pushSendMaxY->setText(QCoreApplication::translate("Temperature", "\345\217\221\351\200\201", nullptr));
        pushSendMaxX->setText(QCoreApplication::translate("Temperature", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Temperature: public Ui_Temperature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPERATURE_H
