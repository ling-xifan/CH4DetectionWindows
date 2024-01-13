#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "humidity.h"
#include "ui_humidity.h"
#include "temperature.h"
#include "ui_temperature.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QMessageBox>
#include <QtNetwork/QTcpServer>                 //监听套接字
#include <QtNetwork/QTcpSocket>                 //通信套接字//对方的(客户端的)套接字(通信套接字)
#include <vector>
#include <QStringListModel>
#include <QStringList>

#include <QDebug>
#include <thread>
#include <mutex>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>

//#include <QReadWriteLock>

#define TIME_CYC 500
#define TIME_SEND 100
#define TIME_60S 10           //一分钟采集的数据个数   每6s采集一次[发送端发送时间间隔6s]
#define BUFFERSIZE 60*60*24*10       //队列寸2小时内的数据
#define	ARRAY 8//阵列信号数
#define SERIES_NUM ARRAY
#define THREAD_NUM 2//线程数

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChart *drawing;
    QLineSeries* series [SERIES_NUM];


private:
    Ui::MainWindow *ui;
 //   Dialog *Dia_Timein;
    Temperature *temperature;
    humidity *rh;
    //图像
    QChartView *drawview;
    QTcpSocket* tcpClient;
    void draw_thread(int start, int end);
    //计时器
    QTimer *JSTimer;
    QTime JSTime;
    QString timeStr;

private slots:
    void updateDisplay();
    void Func_start();
    void Func_stop();
    void Clear_data();
    void Draw_Graph();
    void save_excel();
    void save_txt();
   // void Time_input();
    void save_graph();
    void storeMessage();
    void Series_display();
    void Choose_Channel1_5();
    void Choose_Channel6_10();
    void Volt_Change();
    void ViewT();
    void ViewRH();
    void Volt_Send();
     void Set_Y_Range();

};

#endif // MAINWINDOW_H
