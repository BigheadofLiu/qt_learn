#include "mydialog.h"
#include "ui_mydialog.h"

myDialog::myDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::myDialog)
{
    ui->setupUi(this);
}

myDialog::~myDialog()
{
    delete ui;
}

//Dialog 三种模态阻塞类型 accept、reject、done
/*
 * ===============================
 * QDialog 模态阻塞返回方式对比
 * ===============================
 * 1. accept()
 *    - 等价于 done(QDialog::Accepted)，返回值为 1
 *    - 常用于“确定”按钮
 *
 * 2. reject()
 *    - 等价于 done(QDialog::Rejected)，返回值为 0
 *    - 常用于“取消”按钮或关闭操作
 *
 * 3. done(int)
 *    - 允许自定义返回值，可根据业务自定义状态码
 *    - 例如 done(10)，调用 exec() 时返回 10
 */
void myDialog::on_acceptBtn_clicked()
{
    //执行accept阻塞
    this->accept();

}


void myDialog::on_rejectBtn_clicked()
{
    //执行reject阻塞
    this->reject();
}


void myDialog::on_doneBtn_clicked()
{
    //执行done阻塞
    this->done(10);
    this->done(1); //等价于accept
    this->done(0); //等价于reject
}

