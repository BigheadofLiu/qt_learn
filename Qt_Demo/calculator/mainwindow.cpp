#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "string.h"
#include <QJSEngine> //使用QT自带的库进行预算 不使用自定义栈的方法计算

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->zeroBtn,&QPushButton::clicked,[this](){
    //     this->expression+="0";
    //     ui->caclulatelineEdit->setText(this->expression);
    // }); 使用信号槽替代转到槽
    // ui->equalBtn->setStyleSheet("color:yellow"); #还他妈不生效。。
    ui->equalBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #3498db;"
        "   color: white;"
        "   border-radius: 6px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1f6391;"
        "}"
        );
    connect(ui->equalBtn,&QPushButton::clicked,[this](){
        if(this->expression.isEmpty()){
            return;
        }
        QJSEngine engine;
        QJSValue result=engine.evaluate(this->expression);
        if(result.isError()){
            this->expression.clear();
            ui->caclulatelineEdit->setText("Error");
            return;
        }
        QString res=result.toString();
        ui->caclulatelineEdit->setText(res);
        this->expression=res;
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zeroBtn_clicked()
{
    expression+="0";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_oneBtn_clicked()
{
    expression+="1";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_twoBtn_clicked()
{
     expression+="2";
     ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_threeBtn_clicked()
{
     expression+="3";
     ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_fourBtn_clicked()
{
    expression+="4";
    ui->caclulatelineEdit->setText(expression);
}

void MainWindow::on_fiveBtn_clicked()
{
    expression+="5";
    ui->caclulatelineEdit->setText(expression);
}

void MainWindow::on_sixBtn_clicked()
{
    expression+="6";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_sevenBtn_clicked()
{
    expression+="7";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_eightBtn_clicked()
{
    expression+="8";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_nineBtn_clicked()
{
    expression+="9";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_pointBtn_clicked()
{
    expression+=".";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_deviBtn_clicked()
{
    expression+="/";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_multiBtn_clicked()
{
    expression+="*";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_subBtn_clicked()
{
    expression+="-";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_addBtn_clicked()
{
    expression+="+";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_leftBtn_clicked()
{
    expression+="(";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_rightBtn_clicked()
{
    expression+=")";
    ui->caclulatelineEdit->setText(expression);
}


void MainWindow::on_clearBtn_clicked()
{
    expression.clear();
    ui->caclulatelineEdit->setText(expression);
}



