#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->m_Girl=new GirlFriend;
    this->m_Me=new Me;
#if 0
    // 标准信号槽的使用
    connect(ui->CloseBtn,&QPushButton::clicked,this,&MainWindow::close);
#elif 1
    //自定义信号槽的使用

    // connect(m_Girl,&GirlFriend::hungry,m_Me,&Me::eat);
    // 绑定girlfriend的hungry和me的eat


    //一个信号对应一个槽函数
    // connect(m_Girl,&GirlFriend::hungry,m_Me,&Me::eat);

    //一个信号对应多个槽函数
    //绑定按钮按下与hungry信号发出
    // connect(ui->hungryBtn,&QPushButton::clicked,this,&MainWindow::hungrySlot);
    // connect(ui->hungryBtn,&QPushButton::clicked,this,&MainWindow::eatSlot);
    //两者没有顺序关系

     //多个信号对应一个槽函数
     // connect(ui->hungryBtn2,&QPushButton::clicked,this,&MainWindow::hungrySlot);
     // connect(ui->hungryBtn,&QPushButton::clicked,this,&MainWindow::hungrySlot);

     //信号对应信号（信号转发）

     // connect(ui->hungryBtn,&QPushButton::clicked,m_Girl,&GirlFriend::hungry);
     // connect(m_Girl,&GirlFriend::hungry,m_Me,&Me::eat);

    //QT4绑定方式(不推荐使用 没有编译时检查 容易出错)
    // connect(ui->hungryBtn,SIGNAL(clicked()),this,SLOT(hungrySlot()));
    // connect(m_Girl,SIGNAL(hungry()),m_Me,SLOT(eat())); //无参
    // connect(m_Girl,SIGNAL(hungry(QString)),m_Me,SLOT(eat(QString))); //带参

    // QT5 QT5绑定信号 如果槽函数有多个函数重载 需要使用外部指针
    // auto gril1=&GirlFriend::hungry(); //不能写成函数调用


    auto girl1=static_cast<void (GirlFriend::*)()>(&GirlFriend::hungry);  //方法一：使用static_cast
    // auto girl2=static_cast<void (GirlFriend::*)(QString)>(&GirlFriend::hungry);
    void (GirlFriend::*girl2) (QString)=&GirlFriend::hungry; //方法二：使用函数指针 麻烦的有点看不懂
    void (Me::*me1)()=&Me::eat;
    auto me2=static_cast<void (Me::*)(QString)>(&Me::eat);

    //方法三
    //使用匿名函数
    // connect(ui->hungryBtn,&QPushButton::clicked,this,&MainWindow::hungrySlot);
    connect(ui->hungryBtn,&QPushButton::clicked,this,[=](){
        emit this->m_Girl->hungry();
        emit this->m_Girl->hungry("带你去浪漫的土耳其");
    });

    connect(m_Girl,girl1,m_Me,me1);
    connect(m_Girl,girl2,m_Me,me2);


#elif 0
    // 信号槽的使用说明：

    // 一对一：一个信号连接一个槽函数。
    //         最常见的使用方式，适用于特定事件触发后只需执行一个对应处理逻辑的场景。
    //         例如，按钮点击后弹出一个提示框。

    // 一对多：一个信号连接多个槽函数。
    //         当一个事件发生时，需要同时执行多个处理动作时使用。
    //         所有关联槽会按连接顺序依次执行。
    //         例如，用户登录成功后，既要更新界面，又要写入日志，还可能发出通知。

    // 多对一：多个信号连接同一个槽函数。
    //         不同事件触发同一处理逻辑，适用于多入口统一处理的场景。
    //         例如，不同按钮点击都触发同一个更新函数，根据 sender 判断具体来源。

    //信号连接信号:Qt 支持将一个信号连接到另一个信号，相当于“转发”。
    //         当前对象接收到信号后，自动再发出另一个信号（无需手动 emit）。
    //         常用于模块间的事件传递、中转通信、解耦设计等场景。

    // QT4和QT5连接方式
    // QT4(已废弃):connect(sender, SIGNAL(signalName()), receiver, SLOT(slotName()));
    // 使用字符串形式的 SIGNAL() 和 SLOT() 宏。
    // 运行时解析，不进行编译期类型检查。
    // 容易出错，如拼写错误、参数不匹配，编译也不会报错，但运行时连接会失败。

    //QT5:connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    // Qt5 引入了类型安全的连接方式，可以使用函数指针或 lambda 表达式。

    // 注意事项：
    // - 同一个信号可以重复连接同一个槽，所有连接都会执行。
    // - 信号和槽参数类型和个数应保持一致（或兼容）。
    // - 自定义信号和槽需要使用 Q_OBJECT 宏，且定义在 QObject 子类中。
#endif

}



void MainWindow::eatSlot()
{
    qDebug()<<"带你吃海鲜";
}

MainWindow::~MainWindow()
{
    delete ui;
}
