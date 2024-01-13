#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "xlsxdocument.h"
#include <math.h>
using namespace std;

static int flag_step = 0;


//设置socket信息
static int port = 8090;
static char* ServerIP = "192.168.4.1";
static int  InitPyFlag = 0;
//192.168.4.1:8090
static int X_min = 0, X_max = 50;
static int Y_min = 0, Y_max = 1000;
static int Started = 0;                         //标志是否已开始采集
static QString save_fileName;                   //文件保存名
static vector<vector<float>> array_signal;          //二维数组
static vector<vector<float>> array_signal_save;      //二维数组
vector<float> Temperature_signal;//温度数组
vector<float> RH_signal;//湿度数组
static vector<float> array_time;                    //时间数组
static vector<float> array_time_save;                //时间数组
static vector<float> array_cnt_save;                  //计数数组
static long axisY_max,axisY_min = 0;
static QByteArray buffer;
static int index = -1;
static int cnt = -1;
static int index_save = 0;
static QString volt = "00";
int dp[17] = {0};
static QListView* RT_list[ARRAY+2];
static QStringList text_content[ARRAY+2];//记录文本的变量
static QStringListModel *model_text[ARRAY+2];
static QColor Graph_color[ARRAY] = {
    QColor(255, 0, 0),//大红
    QColor(0, 255, 0),//黑色
    QColor(0, 0, 255),//Cyan
    QColor(255, 0, 255),//MediumSeaGreen
    QColor(255, 125, 0),//goldenrod
    QColor(0, 255, 255),//SandyBrown
    QColor(0, 0, 0),//DarkSeaGreen3
    QColor(125, 125, 0),//Gold2
                       };

//static QTimer *timer_0;//test
static QTimer *timer;
static thread* array_graph[THREAD_NUM];
static QFile file;

//线程同步所需的信号量
static std::mutex bMutex;//互斥锁，防止添加数据或显示数据的时候被打断

int reading = 0;

/************************************************画图线程函数**********************************************/
//每个线程画step条曲线
void MainWindow::draw_thread(int start, int end) {

    while(reading);//等待读结束

    for(int num = start; num <= end; num++) {
        series[num]->setPen(QPen(Graph_color[num], 1, Qt::SolidLine));  // 设置折线显示效果

        if(dp[1] == 0)  series[0]->setPen(QColor(0,0,0,0));//通道隐藏
        if(dp[2] == 0)  series[1]->setPen(QColor(0,0,0,0));
        if(dp[3] == 0)  series[2]->setPen(QColor(0,0,0,0));
        if(dp[4] == 0)  series[3]->setPen(QColor(0,0,0,0));
        if(dp[5] == 0)  series[4]->setPen(QColor(0,0,0,0));
        if(dp[6] == 0)  series[5]->setPen(QColor(0,0,0,0));
        if(dp[7] == 0)  series[6]->setPen(QColor(0,0,0,0));
        if(dp[8] == 0)  series[7]->setPen(QColor(0,0,0,0));
//        qDebug() << "dp: " << array_signal[num][0] << endl;

        for (int i = 0; i <= X_max; i++)
            series[num]->append(-i, array_signal[num][i]/1000);

        //设置listview
        QString s = QString::number(round(array_signal[num][0]/1000));
        text_content[num].clear();
        text_content[num] << s;
    }
    if(end>6)
    {
    QString s = QString::number((Temperature_signal[0]),'f',2);
    text_content[8].clear();
    text_content[8] << s;//显示到listview
    s = QString::number((RH_signal[0]),'f',2);
    text_content[9].clear();
    text_content[9] << s;//显示到listview
    }
    //qDebug() << "drawing" << array_signal[num][0] << endl;
    return;
}

void idle_thread() {
    //空线程函数
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    array_signal.resize(ARRAY, vector<float>(BUFFERSIZE));
    array_signal_save.resize(ARRAY, vector<float>(TIME_60S));
    array_time.resize(BUFFERSIZE);
    array_time_save.resize(TIME_60S);
    array_cnt_save.resize(BUFFERSIZE);
    RH_signal.resize(BUFFERSIZE);
    Temperature_signal.resize(BUFFERSIZE);
        RT_list[0] = ui->list_ch1;
        RT_list[1] = ui->list_ch2;
        RT_list[2] = ui->list_ch3;
        RT_list[3] = ui->list_ch4;
        RT_list[4] = ui->list_ch5;
        RT_list[5] = ui->list_ch6;

        RT_list[6] = ui->list_ch7;
        RT_list[7] = ui->list_ch8;
        RT_list[8] = ui->list_T;
        RT_list[9] = ui->list_RH;

    tcpClient = new QTcpSocket(this);   //实例化tcpClient
    for (int i = 0; i < ARRAY+2; i++)     //这里并不是很懂是什么
        model_text[i] = new QStringListModel(text_content[i]);
    for (int i = 0; i < ARRAY; i++)
        series[i] = new QLineSeries;
    ui->checkBox->setStyleSheet("QCheckBox{color:rgb(255, 0, 0)}");
    ui->checkBox_2->setStyleSheet("QCheckBox{color:rgb(0, 255, 0)}");
    ui->checkBox_3->setStyleSheet("QCheckBox{color:rgb(0, 0, 255)}");
    ui->checkBox_4->setStyleSheet("QCheckBox{color:rgb(255, 0, 255)}");
    ui->checkBox_5->setStyleSheet("QCheckBox{color:rgb(255, 125, 0)}");
    ui->checkBox_6->setStyleSheet("QCheckBox{color:rgb(0, 255, 255)}");
    ui->checkBox_7->setStyleSheet("QCheckBox{color:rgb(0, 0, 0)}");
    ui->checkBox_8->setStyleSheet("QCheckBox{color:rgb(125, 125, 0)}");
    /*****************设置标题和图标***********************/
    setWindowTitle(u8"甲烷气体检测");
    /**********************新建子窗口************************/
    temperature= new Temperature(this);
    temperature->close();
    rh= new humidity(this);
   rh->close();

    /*****************设置计时器***********************/
    ui->lcdNumber->display("00:00");
    JSTimer = new QTimer;

    /**********************连接槽函数************************/
    //connect(Dia_Timein->ui->pushButton_OK, SIGNAL(clicked()), this, SLOT(Func_start()));
    connect(JSTimer,SIGNAL(timeout()),this,SLOT(updateDisplay()));
    connect(ui->pushStart, SIGNAL(clicked()), this, SLOT(Func_start()));
    connect(ui->pushStop, SIGNAL(clicked()), this, SLOT(Func_stop()));
    connect(ui->pushClear, SIGNAL(clicked()), this, SLOT(Clear_data()));
 connect(ui->pushSendMax,&QPushButton::clicked,this,&MainWindow::Set_Y_Range);
    connect(ui->action_txt, SIGNAL(triggered()), this, SLOT(save_txt()));
    connect(ui->action_excel, SIGNAL(triggered()), this, SLOT(save_excel()));
    connect(ui->action_graph, SIGNAL(triggered()), this, SLOT(save_graph()));
    connect(ui->checkBox_17,SIGNAL(clicked()),this,SLOT(Choose_Channel1_5()));
    connect(ui->checkBox_18,SIGNAL(clicked()),this,SLOT(Choose_Channel6_10()));
   // connect(ui->comboCHchoose, SIGNAL(currentIndexChanged(QString)), this, SLOT(Series_display()));
    connect(ui->pushT,&QPushButton::clicked,this,&MainWindow::ViewT);
     connect(ui->pushRH,&QPushButton::clicked,this,&MainWindow::ViewRH);
    connect(ui->comboVolt1, SIGNAL(currentIndexChanged(QString)), this, SLOT(Volt_Change()));
        connect(ui->comboVolt2, SIGNAL(currentIndexChanged(QString)), this, SLOT(Volt_Change()));
    connect(ui->pushVoltage, SIGNAL(clicked()), this, SLOT(Volt_Send()));


    /***********************画图*****************************/
    drawing = new QChart;
    drawing->setTitle(u8"传感器响应曲线");
    drawview = new QChartView(drawing);
    axisX = new QValueAxis;
    axisY = new QValueAxis;
    //建立数据源队列

    //建立坐标轴
    QBrush AxisColor;
    AxisColor.setColor(Qt::black);
    axisX->setRange(-50, 0);                // 设置范围
    axisX->setLabelFormat("%d");                            // 设置刻度的格式
    axisX->setGridLineVisible(true);                        // 网格线可见
    axisX->setTickCount(6);                                 // 设置多少个大格
    axisX->setMinorTickCount(1);                            // 设置每个大格里面小刻度线的数目
    axisX->setTitleText(u8"时间");                             // 设置描述

    axisY->setRange(0, 100);
    axisY->setLabelFormat("%.1f");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(8);
    axisY->setMinorTickCount(1);
    axisY->setTitleText(u8"数据");
    //为曲线添加坐标轴
    drawing->addAxis(axisX, Qt::AlignBottom);               // 下：Qt::AlignBottom  上：Qt::AlignTop
    drawing->addAxis(axisY, Qt::AlignLeft);                 // 左：Qt::AlignLeft    右：Qt::AlignRight
    drawing->legend()->hide();                              //隐藏图例
    //chart放入chartview内
    drawview->setRenderHint(QPainter::Antialiasing);        //防止图形走样
    ui->verticalLayout_5->addWidget(drawview);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::Time_input()
//{
//    Dia_Timein->show();
//}
/*******************************************槽函数************************************************/
void MainWindow::ViewT()
{
    qDebug() << "showT";
    if(Started)
    {
         // bMutex.unlock();
          temperature->draw_begin();
    }

    temperature->show();

}

void MainWindow::ViewRH()
{
    qDebug() << "showRH";
    if(Started)
    {
          rh->drawRH_begin();
        //  bMutex.unlock();
    }

    rh->show();

}
void MainWindow::Func_start()
{

//    //选择文件保存路径
//    save_fileName = QFileDialog::getSaveFileName(this, "Save",
//        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
//        "text files(*.txt)");
//    file.setFileName(save_fileName);

    //开始采集
    switch (QMessageBox::question(this, u8"提示", u8"确认开始采集？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
    if (Started == 1);//do nothing
    else
    {
        //为坐标轴改范围
        //为坐标轴改范围


//        for (int j = ARRAY+2; j < ARRAY+2; j++)
//        {
//            model_text[j] = new QStringListModel(text_content[j]);
//            model_text[j]->setStringList(text_content[j]);
//            RT_list[j]->setModel(model_text[j]);
//        }
//        //axisY->setRange(Y_min, Y_max);



        timer = new QTimer;
        timer->start(TIME_CYC);
        for (int j = 0; j < THREAD_NUM; j++)
            array_graph[j] = new std::thread(idle_thread);//创建空闲线程
        for (int j = 0; j < THREAD_NUM; j++)
            array_graph[j]->join();
        //connect(timer, SIGNAL(timeout()), this, SLOT(Draw_Graph()));
        qDebug() << "start" << endl;//debug

        //初始化TCP客户端
        delete tcpClient;
        tcpClient = new QTcpSocket(this);   //实例化tcpClient
        tcpClient->abort();                 //取消原有连接
        tcpClient->connectToHost(ServerIP, port);
        connect(tcpClient, SIGNAL(readyRead()), this, SLOT(storeMessage()));
        if (tcpClient->waitForConnected(1000))  // 连接成功则进入if{}
        {
            connect(timer, SIGNAL(timeout()), this, SLOT(Draw_Graph()));        //每50ms执行一次这个函数？
            //tcpClient->write("handshake");//先发一个才有回应
            Started = 1;

            //获取当前时间给计时器
            JSTime = JSTime.currentTime();
            JSTimer->start(1);
        }
        else
        {
            QMessageBox::warning(this, "Error", u8"服务器连接失败");
            break;
        }
    }
        break;
    case QMessageBox::No:
        //do nothing
        break;
    default:
        break;
    }
}

void MainWindow::Func_stop()
{
    switch (QMessageBox::question(this, u8"提示", u8"确认停止采集？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
    case QMessageBox::Yes:
        if (Started == 0);//do nothing
        else {
            Started = 0;

            for (int j = 0; j < THREAD_NUM; j++)
            {
                delete array_graph[j];//删除线程
            }

            //test
            //timer_0->stop();
            //delete timer_0;
            tcpClient->abort();
            tcpClient->close();

            timer->stop();
            delete timer;//删除采集线程

            JSTimer->stop();
        }
        break;
    case QMessageBox::No:
        //do nothing
        break;
    default:
        break;
    }
}

/*************功能：清空数据区和曲线******************/
//只有在不采集的情况下才能清空
//不仅清空显示，缓存里已有的数据也会清空

void MainWindow::Clear_data()
{
    if (Started) {
        //do nothing
    }
    else {
        for (int i = 0; i < ARRAY; i++)
        {
            text_content[i].clear();
            series[i]->clear();
        }
        index = -1;
        cnt = -1;
        array_signal.clear();
        array_time.clear();
        array_cnt_save.clear();

        array_time.resize(BUFFERSIZE);
        array_cnt_save.resize(BUFFERSIZE);
        array_signal.resize(ARRAY, vector<float>(BUFFERSIZE));

        //清除计时器
        ui->lcdNumber->display("00:00");
    }
}

void MainWindow::save_excel()
{
    //行数列数
    int row_num = index;


    QXlsx::Document xlsx;
    xlsx.write("A1", u8"通道一(Ω)"); xlsx.write("B1", u8"通道二(Ω)"); xlsx.write("C1", u8"通道三(Ω)");
    xlsx.write("D1", u8"通道四(Ω)"); xlsx.write("E1", u8"通道五(Ω)"); xlsx.write("F1", u8"通道六(Ω)");
    xlsx.write("G1", u8"通道七(Ω)"); xlsx.write("H1", u8"通道八(Ω)"); xlsx.write("I1", u8"湿度(%)");
    xlsx.write("J1", u8"温度(℃)");

    for (int i = 0; i <= row_num; i++) {
        for(int j = 0; j< ARRAY; j++)
            xlsx.write(i + 2, j + 1, array_signal[j][i]);
        xlsx.write(i + 2, 9, RH_signal[i]);
        xlsx.write(i + 2, 10, Temperature_signal[i]);//row col
    }
    QString fileName = QFileDialog::getSaveFileName(this, "Save",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        "Excel files(*.xlsx *.xls)");
    xlsx.saveAs(QDir::toNativeSeparators(fileName));
}

/*************功能：数据保存成txt*********************/
void MainWindow::save_txt()
{
    QString save_fileName = QFileDialog::getSaveFileName(this, "Save",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        "text files(*.txt)");

    //对文件进行操作
    QFile file(save_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        //QMessageBox::warning(this, "Error", u8"打开失败", QMessageBox::Yes);
        return;
    }
    QTextStream in(&file);

    for (int i = index - 1; i >= 0; i--) //越往上越靠近初始
    {
        in << array_cnt_save[i];
        for(int j = 0; j < ARRAY; j++)
        {
            in << "	" << array_signal[j][i];
        }
        in << "	" << RH_signal[i];
        in << "	" << Temperature_signal[i];
        in << "\n";
    }

    file.close();
}


/*************功能：保存图像**************************/
void MainWindow::save_graph()
{
    QPixmap save_P = QPixmap::grabWidget(drawview);
    QString save_fileName = QFileDialog::getSaveFileName(this, "Save",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        "graph files(*.png *.jpg *.bmp)");

    save_P.save(save_fileName);
}

/*************功能：画图（定时器）并显示实时数据******/
/*开六个线程画*/
void MainWindow::Draw_Graph()
{
    int j = 0;
    if((index)<50)
        X_max = 50;
    else
        X_max = index+1;

    axisX->setRange(-X_max, 0);
    qDebug() << "draw" << endl;//debug
    for (j = 0; j < THREAD_NUM; j++)
        delete array_graph[j];
    for (j = 0; j < ARRAY; j++) {
        delete series[j];
        series[j] = new QLineSeries;
        delete model_text[j];
    }
    // qDebug() <<"end error2";
     delete model_text[8];
Series_display();//勾选通道

     model_text[8] = new QStringListModel(text_content[8]);
     model_text[8]->setStringList(text_content[8]);
     RT_list[8]->setModel(model_text[8]);
    // qDebug() <<"end error3";
     delete model_text[9];
     model_text[9] = new QStringListModel(text_content[9]);
     model_text[9]->setStringList(text_content[9]);
     RT_list[9]->setModel(model_text[9]);
    //目前只开2个线程，共6条曲线
    for (j = 0; j < THREAD_NUM; j++) {
        array_graph[j] = new std::thread(&MainWindow::draw_thread, this, j*ARRAY/THREAD_NUM, (j+1)*ARRAY / THREAD_NUM - 1);//创建画图线程
    }

    for (j = 0; j < THREAD_NUM; j++)
        array_graph[j]->join();
    for (j = 0; j < ARRAY; j++) {
        drawing->addSeries(series[j]);
        drawing->setAxisX(axisX, series[j]);
        drawing->setAxisY(axisY, series[j]);

        model_text[j] = new QStringListModel(text_content[j]);
        model_text[j]->setStringList(text_content[j]);
        RT_list[j]->setModel(model_text[j]);
    }
    //qDebug() << (index + 1) << endl;
}
/*************功能：坐标轴手动设置**********************/
void MainWindow::Set_Y_Range()
{

        if(!ui->linemax->text().isEmpty()&&!ui->linemin->text().isEmpty())//设置内容不能为空
        {
            axisY_max = ui->linemax->text().toInt();//将文本框中内容转换为int数据
            axisY_min = ui->linemin->text().toInt();//将文本框中内容转换为int数据
            axisY->setRange(axisY_min, axisY_max);//设置范围
        }

}
/*************功能：读取数据（可读时刻）**************/
void MainWindow::storeMessage()
{
    reading = 1;

    qDebug() << "read" << endl;

    //读取当时时间
    QTime currTime = QTime::currentTime();
    int t = JSTime.msecsTo(currTime);
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(t);



    //读取缓冲区数据
    QByteArray buffer = tcpClient->readAll();         //ARRAY*4个字节
//    qDebug() << "size:" << buffer.size() << endl;
//    qDebug() << buffer.toHex() << endl;

    cnt++;
    array_cnt_save.insert(array_cnt_save.begin(), cnt*0.5-0.5);
    if (index < BUFFERSIZE) index++;                  //用来判断数据是否超过了2h的数据量
    for (int i = 0; i < ARRAY; i++) {
        if (index >= BUFFERSIZE)  array_signal.at(i).pop_back();
        uint buf_0 = ((uint)buffer.at(4 * i))&0x000000ff;
        uint buf_1 = ((uint)(buffer.at(4 * i + 1)) << 8) & 0x0000ff00;
        uint buf_2 = ((uint)(buffer.at(4 * i + 2)) << 16) & 0x00ff0000;
        uint buf_3 = ((uint)(buffer.at(4 * i + 3)) << 24) & 0xff000000;
        uint buf = buf_0 + buf_1 + buf_2 + buf_3;
        //qDebug() << hex << buf_0 << buf_1 << buf_2 << buf_3 << endl;
        //qDebug() << hex << buf << endl;
        array_signal.at(i).insert(array_signal.at(i).begin(),
            *(float*)&buf);
    }
    uint buf_0 = ((uint)buffer.at(4 * 8))&0x000000ff;
    uint buf_1 = ((uint)(buffer.at(4 * 8 + 1)) << 8) & 0x0000ff00;
    uint buf_2 = ((uint)(buffer.at(4 * 8 + 2)) << 16) & 0x00ff0000;
    uint buf_3 = ((uint)(buffer.at(4 * 8 + 3)) << 24) & 0xff000000;
    uint buf = buf_0 + buf_1 + buf_2 + buf_3;
    Temperature_signal.insert(Temperature_signal.begin(),(*(float*)&buf)/100.0);
   //  qDebug() <<"checkcum 2!";
    buf_0 = ((uint)buffer.at(4 * 9))&0x000000ff;
     buf_1 = ((uint)(buffer.at(4 * 9 + 1)) << 8) & 0x0000ff00;
     buf_2 = ((uint)(buffer.at(4 * 9 + 2)) << 16) & 0x00ff0000;
     buf_3 = ((uint)(buffer.at(4 * 9 + 3)) << 24) & 0xff000000;
     buf = buf_0 + buf_1 + buf_2 + buf_3;
    RH_signal.insert(RH_signal.begin(),(*(float*)&buf)/100.0);


    //时间处理
    QString str_mtime = showTime.toString("mm");
    QString str_stime = showTime.toString("ss.zzz");
    float flo_mtime = str_mtime.toFloat();
    float flo_stime = str_stime.toFloat();
    float flo_time = flo_mtime*60+flo_stime;
    qDebug() << "time: " << flo_time << endl;
    array_time.insert(array_time.begin(), flo_time);

    reading = 0;
}


/*************功能：隐藏曲线**********************/
/*************功能：隐藏曲线**********************/
void MainWindow::Series_display()
{
    if(ui->checkBox_17->isChecked())
    {
        for(int i = 1;i<5;i++)
            dp[i] = 1;
    }
    else
    {
    if(ui->checkBox->isChecked())
        dp[1] = 1;
    else
        dp[1] = 0;
    if(ui->checkBox_2->isChecked())
        dp[2] = 1;
    else
        dp[2] = 0;
    if(ui->checkBox_3->isChecked())
        dp[3] = 1;
    else
        dp[3] = 0;
    if(ui->checkBox_4->isChecked())
        dp[4] = 1;
    else
        dp[4] = 0;
    }
    if(ui->checkBox_18->isChecked())
    {
        for(int i = 5;i<9;i++)
            dp[i] = 1;
    }
    else{

     if(ui->checkBox_5->isChecked())
            dp[5] = 1;
        else
            dp[5] = 0;
    if(ui->checkBox_6->isChecked())
        dp[6] = 1;
    else
        dp[6] = 0;
    if(ui->checkBox_7->isChecked())
        dp[7] = 1;
    else
        dp[7] = 0;
    if(ui->checkBox_8->isChecked())
        dp[8] = 1;
    else
        dp[8] = 0;

    }
}
/*************功能：隐藏曲线**********************/
void MainWindow::Choose_Channel1_5()
{
    if(ui->checkBox_17->isChecked())
    {
        ui->checkBox->setCheckState(Qt::Checked);
        ui->checkBox_2->setCheckState(Qt::Checked);
        ui->checkBox_3->setCheckState(Qt::Checked);
        ui->checkBox_4->setCheckState(Qt::Checked);


    }
    else
    {
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->checkBox_2->setCheckState(Qt::Unchecked);
        ui->checkBox_3->setCheckState(Qt::Unchecked);
        ui->checkBox_4->setCheckState(Qt::Unchecked);

    }

}
/*************功能：隐藏曲线**********************/
void MainWindow::Choose_Channel6_10()
{

     if(ui->checkBox_18->isChecked())
    {
        ui->checkBox_5->setCheckState(Qt::Checked);
        ui->checkBox_6->setCheckState(Qt::Checked);
        ui->checkBox_7->setCheckState(Qt::Checked);
        ui->checkBox_8->setCheckState(Qt::Checked);

    }
     else
     {
         ui->checkBox_5->setCheckState(Qt::Unchecked);
         ui->checkBox_6->setCheckState(Qt::Unchecked);
         ui->checkBox_7->setCheckState(Qt::Unchecked);
         ui->checkBox_8->setCheckState(Qt::Unchecked);

     }
}
/*************功能：改变控温电压**********************/
void MainWindow::Volt_Change()
{

    switch (ui->comboVolt1->currentIndex())
    {
        case 0: volt[0] = '0'; break;
        case 1: volt[0] = '1'; break;
        case 2: volt[0] = '2'; break;
        case 3: volt[0] = '3'; break;
        case 4: volt[0] = '4'; break;
        case 5: volt[0] = '5'; break;
        //default: volt = volt.replace(0,1,5); break;
    }
    switch (ui->comboVolt2->currentIndex())
    {
        case 0: volt[1] = '0'; break;
        case 1: volt[1] = '1'; break;
        case 2: volt[1] = '2'; break;
        case 3: volt[1] = '3'; break;
        case 4: volt[1] = '4'; break;
        case 5: volt[1] = '5'; break;
   // default: volt = volt.replace(0,1,5); break;
    }
qDebug() <<ui->comboVolt2->currentIndex();
}

/*************功能：发送控温电压**********************/
void MainWindow::Volt_Send()
{
    QString sendvolt = "Already send:";
    sendvolt = sendvolt.insert(13,volt);
    if (Started) //当已经开启socket，就不需要再创建
    {
        tcpClient->write(volt.toLatin1());        //发电压
    }
    else {//否则需要创建
        //初始化TCP客户端
        delete tcpClient;
        tcpClient = new QTcpSocket(this);   //实例化tcpClient
        tcpClient->abort();                 //取消原有连接
        tcpClient->connectToHost(ServerIP, port);
        if (tcpClient->waitForConnected(1000))
        {// 连接成功则进入if{}
            tcpClient->write(volt.toLatin1());        //发电压
        }
        else {
            QMessageBox::warning(this, "Error", u8"服务器连接失败");
            return;
        }
        tcpClient->waitForBytesWritten(1);
        tcpClient->close();
    }
   QMessageBox::warning(this, "Congratulation", sendvolt);
}

/*************功能：更新计时器时间******************/
void MainWindow::updateDisplay()
{
    /*
     * 1.点击开始后获取到当前的时间并且赋值给JSTime
     * 2.启动定时器,间隔1s
     * 3.槽函数中再次获取当前的时间currTime
     * 4.计算两个时间的差值t
     * 5.声明一个showTime对象给他加上t的差值
     * 6.格式化后设置显示
     */
    QTime currTime = QTime::currentTime();
    int t = JSTime.msecsTo(currTime);
    QTime showTime(0,0,0,0);
    showTime = showTime.addMSecs(t);
    timeStr = showTime.toString("mm:ss");
    ui->lcdNumber->display(timeStr);

    flag_step = t;
}






