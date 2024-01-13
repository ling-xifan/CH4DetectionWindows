/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_txt;
    QAction *action_excel;
    QAction *action_graph;
    QWidget *centralWidget;
    QLabel *label_14;
    QPushButton *pushStart;
    QPushButton *pushClear;
    QListView *list_ch2;
    QListView *list_ch1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QListView *list_ch3;
    QFrame *line_2;
    QPushButton *pushStop;
    QLabel *label_13;
    QComboBox *comboVolt1;
    QFrame *line;
    QPushButton *pushVoltage;
    QListView *list_ch6;
    QListView *list_ch4;
    QListView *list_ch5;
    QLCDNumber *lcdNumber;
    QListView *list_ch8;
    QListView *list_ch7;
    QListView *list_RH;
    QListView *list_T;
    QComboBox *comboVolt2;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *pushT;
    QPushButton *pushRH;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_17;
    QLabel *label_4;
    QLabel *label_9;
    QPushButton *pushSendMax;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *linemin;
    QLineEdit *linemax;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1261, 665);
        action_txt = new QAction(MainWindow);
        action_txt->setObjectName(QString::fromUtf8("action_txt"));
        action_excel = new QAction(MainWindow);
        action_excel->setObjectName(QString::fromUtf8("action_excel"));
        action_graph = new QAction(MainWindow);
        action_graph->setObjectName(QString::fromUtf8("action_graph"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(1180, 30, 41, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        label_14->setFont(font);
        pushStart = new QPushButton(centralWidget);
        pushStart->setObjectName(QString::fromUtf8("pushStart"));
        pushStart->setGeometry(QRect(1080, 240, 130, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(16);
        pushStart->setFont(font1);
        pushClear = new QPushButton(centralWidget);
        pushClear->setObjectName(QString::fromUtf8("pushClear"));
        pushClear->setGeometry(QRect(1080, 460, 130, 81));
        pushClear->setFont(font1);
        list_ch2 = new QListView(centralWidget);
        list_ch2->setObjectName(QString::fromUtf8("list_ch2"));
        list_ch2->setGeometry(QRect(510, 10, 81, 25));
        QFont font2;
        font2.setPointSize(11);
        list_ch2->setFont(font2);
        list_ch1 = new QListView(centralWidget);
        list_ch1->setObjectName(QString::fromUtf8("list_ch1"));
        list_ch1->setGeometry(QRect(350, 10, 81, 25));
        list_ch1->setFont(font2);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 140, 971, 451));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        list_ch3 = new QListView(centralWidget);
        list_ch3->setObjectName(QString::fromUtf8("list_ch3"));
        list_ch3->setGeometry(QRect(670, 10, 81, 25));
        list_ch3->setFont(font2);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(250, 0, 20, 131));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushStop = new QPushButton(centralWidget);
        pushStop->setObjectName(QString::fromUtf8("pushStop"));
        pushStop->setGeometry(QRect(1080, 350, 130, 81));
        pushStop->setFont(font1);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1080, 30, 81, 21));
        label_13->setFont(font);
        comboVolt1 = new QComboBox(centralWidget);
        comboVolt1->addItem(QString());
        comboVolt1->addItem(QString());
        comboVolt1->addItem(QString());
        comboVolt1->addItem(QString());
        comboVolt1->addItem(QString());
        comboVolt1->addItem(QString());
        comboVolt1->setObjectName(QString::fromUtf8("comboVolt1"));
        comboVolt1->setGeometry(QRect(1080, 69, 81, 31));
        comboVolt1->setFont(font);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(1010, 0, 20, 601));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushVoltage = new QPushButton(centralWidget);
        pushVoltage->setObjectName(QString::fromUtf8("pushVoltage"));
        pushVoltage->setGeometry(QRect(1180, 89, 61, 31));
        pushVoltage->setFont(font);
        list_ch6 = new QListView(centralWidget);
        list_ch6->setObjectName(QString::fromUtf8("list_ch6"));
        list_ch6->setGeometry(QRect(510, 50, 81, 25));
        list_ch6->setFont(font2);
        list_ch4 = new QListView(centralWidget);
        list_ch4->setObjectName(QString::fromUtf8("list_ch4"));
        list_ch4->setGeometry(QRect(820, 10, 81, 25));
        list_ch4->setFont(font2);
        list_ch5 = new QListView(centralWidget);
        list_ch5->setObjectName(QString::fromUtf8("list_ch5"));
        list_ch5->setGeometry(QRect(350, 50, 81, 25));
        list_ch5->setFont(font2);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(290, 90, 171, 41));
        list_ch8 = new QListView(centralWidget);
        list_ch8->setObjectName(QString::fromUtf8("list_ch8"));
        list_ch8->setGeometry(QRect(820, 50, 81, 25));
        list_ch8->setFont(font2);
        list_ch7 = new QListView(centralWidget);
        list_ch7->setObjectName(QString::fromUtf8("list_ch7"));
        list_ch7->setGeometry(QRect(670, 50, 81, 25));
        list_ch7->setFont(font2);
        list_RH = new QListView(centralWidget);
        list_RH->setObjectName(QString::fromUtf8("list_RH"));
        list_RH->setGeometry(QRect(810, 100, 91, 31));
        list_RH->setFont(font2);
        list_T = new QListView(centralWidget);
        list_T->setObjectName(QString::fromUtf8("list_T"));
        list_T->setGeometry(QRect(550, 100, 91, 31));
        list_T->setFont(font2);
        comboVolt2 = new QComboBox(centralWidget);
        comboVolt2->addItem(QString());
        comboVolt2->addItem(QString());
        comboVolt2->addItem(QString());
        comboVolt2->addItem(QString());
        comboVolt2->addItem(QString());
        comboVolt2->addItem(QString());
        comboVolt2->setObjectName(QString::fromUtf8("comboVolt2"));
        comboVolt2->setGeometry(QRect(1080, 110, 81, 31));
        comboVolt2->setFont(font);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(910, 110, 31, 20));
        label_21->setFont(font);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(650, 110, 31, 20));
        label_22->setFont(font);
        pushT = new QPushButton(centralWidget);
        pushT->setObjectName(QString::fromUtf8("pushT"));
        pushT->setGeometry(QRect(490, 100, 51, 31));
        pushT->setFont(font);
        pushRH = new QPushButton(centralWidget);
        pushRH->setObjectName(QString::fromUtf8("pushRH"));
        pushRH->setGeometry(QRect(750, 100, 51, 31));
        pushRH->setFont(font);
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setGeometry(QRect(300, 10, 41, 25));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        checkBox->setFont(font3);
        checkBox->setChecked(true);
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(460, 10, 41, 25));
        checkBox_2->setFont(font3);
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(620, 10, 41, 25));
        checkBox_3->setFont(font3);
        checkBox_3->setChecked(true);
        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(780, 10, 41, 25));
        checkBox_4->setFont(font3);
        checkBox_4->setChecked(true);
        checkBox_5 = new QCheckBox(centralWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(300, 50, 41, 25));
        checkBox_5->setFont(font3);
        checkBox_5->setChecked(true);
        checkBox_6 = new QCheckBox(centralWidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(460, 50, 41, 25));
        checkBox_6->setFont(font3);
        checkBox_6->setChecked(true);
        checkBox_7 = new QCheckBox(centralWidget);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(620, 50, 41, 25));
        checkBox_7->setFont(font3);
        checkBox_7->setChecked(true);
        checkBox_8 = new QCheckBox(centralWidget);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(780, 50, 41, 25));
        checkBox_8->setFont(font3);
        checkBox_8->setChecked(true);
        checkBox_18 = new QCheckBox(centralWidget);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setGeometry(QRect(930, 50, 50, 21));
        checkBox_18->setChecked(true);
        checkBox_17 = new QCheckBox(centralWidget);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setGeometry(QRect(930, 10, 50, 21));
        checkBox_17->setChecked(true);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 10, 70, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        label_4->setFont(font4);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 60, 41, 30));
        label_9->setFont(font);
        pushSendMax = new QPushButton(centralWidget);
        pushSendMax->setObjectName(QString::fromUtf8("pushSendMax"));
        pushSendMax->setGeometry(QRect(70, 100, 131, 28));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 10, 41, 30));
        label_5->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 60, 61, 30));
        label_3->setFont(font4);
        linemin = new QLineEdit(centralWidget);
        linemin->setObjectName(QString::fromUtf8("linemin"));
        linemin->setGeometry(QRect(70, 60, 141, 30));
        linemin->setFont(font);
        linemax = new QLineEdit(centralWidget);
        linemax->setObjectName(QString::fromUtf8("linemax"));
        linemax->setGeometry(QRect(70, 10, 141, 30));
        linemax->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1261, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_txt);
        menu->addAction(action_excel);
        menu->addAction(action_graph);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_txt->setText(QCoreApplication::translate("MainWindow", "save as txt", nullptr));
        action_excel->setText(QCoreApplication::translate("MainWindow", "save as excel", nullptr));
        action_graph->setText(QCoreApplication::translate("MainWindow", "save as graph", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\357\274\210V\357\274\211", nullptr));
        pushStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        pushClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        pushStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\203\255\347\224\265\345\216\213", nullptr));
        comboVolt1->setItemText(0, QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", nullptr));
        comboVolt1->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboVolt1->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboVolt1->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboVolt1->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboVolt1->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));

        pushVoltage->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        comboVolt2->setItemText(0, QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", nullptr));
        comboVolt2->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboVolt2->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboVolt2->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboVolt2->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboVolt2->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));

        label_21->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\342\204\203", nullptr));
        pushT->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        pushRH->setText(QCoreApplication::translate("MainWindow", "RH", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        checkBox_18->setText(QCoreApplication::translate("MainWindow", "ALL", nullptr));
        checkBox_17->setText(QCoreApplication::translate("MainWindow", "ALL", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\200\274", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "k\316\251", nullptr));
        pushSendMax->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "k\316\251", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\200\274", nullptr));
        linemin->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        linemax->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
