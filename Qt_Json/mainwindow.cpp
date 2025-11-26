#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // writeJson();
    readJson();
}

//json
// {
//     "name":"Shinoda Yu",
//     "sex":"woman",
//     "age":34,
//     "job":"adult actress",
//     "introduce":{
//         "city":"tokoy",
//         "office":"t-powers",
//         "hobby":["DVD","music","Dance"],
//         "cpu":"E",
//         "feature":"peach butt"
//     },
//     "masterpiece":["ssni-233","ssni-313","..."]
// }

void MainWindow::writeJson()
{
    //json格式写入
    QJsonObject obj;
    obj.insert("name","Shinoda Yu");
    obj.insert("sex","woman");
    obj.insert("age",34);
    obj.insert("job","adult actress");

    QJsonObject subObj;
    subObj.insert("city","tokoy");
    subObj.insert("office","t-powers");

    QJsonArray arry1;
    arry1.append("DVD");
    arry1.append("music");
    arry1.append("Dance");
    subObj.insert("hobby",arry1);

    subObj.insert("cpu","E");
    subObj.insert("feature","peach butt");
    obj.insert("introduce",subObj);

    QJsonArray arry2;
    arry2.append("ssni-233");
    arry2.append("ssni-313");
    arry2.append("...");
    obj.insert("masterpiece",arry2);

    QJsonDocument doc(obj);  //建立json转换的桥梁
    QByteArray json=doc.toJson();  //使用数组存储json格式

    QFile file("/home/wdnmd/桌面/test.json");
    file.open(QFile::WriteOnly);
    file.write(json);
    qDebug()<<"json写入成功！\n";
    file.close();
}

void MainWindow::readJson()
{
    QFile file("/home/wdnmd/桌面/test.json");
    file.open(QFile::ReadOnly);
    QByteArray arry=file.readAll();
    file.close();
    QJsonDocument docObj=QJsonDocument::fromJson(arry);
    if(docObj.isObject()){
        QJsonObject obj=docObj.object();
        qDebug()<<"json文件读取成功！\n";
        //遍历json这么麻烦。。。
        for(auto& i:obj.keys()){
            qDebug()<<i<<"-->"<<obj[i]<<"\n";
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
