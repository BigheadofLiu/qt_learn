    #include "sendfilewindow.h"
    #include "./ui_sendfilewindow.h"
    #include "sendfile.h"
    #include <QDebug>
    using namespace  std;

    sendFileWindow::sendFileWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::sendFileWindow)
    {
        //客户端界面
        //界面初始化
        ui->setupUi(this);
        this->setWindowTitle("客户端");
        ui->ipLineEdit->setText("127.0.0.1");
        ui->portLineEdit->setText("8899");
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->disconnectBtn->setEnabled(false);
        ui->sendFileBtn->setEnabled(false);
        // ui->connectBtn->setEnabled(true);
        //创建子线程
        // QThread* t1=new QThread();
        mThread=new QThread();

        // sendFile * send=new sendFile();
        mSend=new sendFile();

        // send->moveToThread(t1);
        mSend->moveToThread(mThread);

        // t1->start();
        mThread->start();
        //信号槽绑定
        connect(this,&sendFileWindow::startconnect,mSend,&sendFile::connectServer/*,Qt::QueuedConnection*/);

        // ui->connectBtn->setEnabled(false);
        connect(mSend,&sendFile::isConnected,this,[=](){
            // QMessageBox::information(this,"Tips","已连接服务器");
            qDebug()<<"连接成功！";
            ui->connectBtn->setEnabled(false);
            ui->disconnectBtn->setEnabled(true);
            ui->sendFileBtn->setEnabled(true);
        });

        connect(mSend,&sendFile::disConnected,this,[=](){
            // QMessageBox::information(this,"Tips","已断开连接服务器");
            qDebug()<<"断开连接！";
            //释放资源（为啥不交给对象树处理）
            ui->connectBtn->setEnabled(true);
            ui->connectBtn->setEnabled(true);
            ui->disconnectBtn->setEnabled(false);
            ui->sendFileBtn->setEnabled(false);

            // t1->quit();
            // t1->wait();
            // send->deleteLater(); //不能delelte 不然只能传一次文件？ 但是不删除，又会裸指针？
            // t1->deleteLater();

            mThread->quit();
            mThread->wait();
            // mSend=nullptr;
            // mThread=nullptr;
            mSend->deleteLater();
            mThread->deleteLater();
        });
        connect(this,&sendFileWindow::disconnect,mSend,&sendFile::disConnected);
        connect(mSend,&sendFile::curPercent,ui->progressBar,&QProgressBar::value); //进度条刷新
        connect(this,&sendFileWindow::sendFilePath,mSend,&sendFile::fileSend);   //发送文件目录
    }

    sendFileWindow::~sendFileWindow()
    {
        delete ui;
    }

    void sendFileWindow::on_choseFileBtn_clicked() //选择文件目录
    {
        QString filepath =QFileDialog::getOpenFileName(); //固定用法
        if(filepath.isEmpty()){
            QMessageBox::warning(this,"Tips","未选择文件或非法空路径！");
            return;
        }
        ui->filePathlineEdit->setText(filepath);
    }


    void sendFileWindow::on_connectBtn_clicked()
    {
        QString ip= ui->ipLineEdit->text();
        unsigned short port=ui->portLineEdit->text().toUShort();
        emit this->startconnect(ip,port);
    }


    void sendFileWindow::on_disconnectBtn_clicked()
    {
        emit disconnect();
    }


    void sendFileWindow::on_sendFileBtn_clicked()
    {
        emit sendFilePath(ui->filePathlineEdit->text());
    }

    // void sendFileWindow::startconnect(QString ip,unsigned short port)
    // {

    // }




