#include "testqwidget.h"
#include "ui_testqwidget.h"

/**
 * QWidget —— 所有可视窗口部件（控件）的基类
 *
 * 1. QWidget 是 Qt 中所有界面组件（如按钮、标签、窗口等）的基类。
 *
 * 2. 可作为**子控件**内嵌到其他窗口中：
 *    - 只需设置父对象（parent）；
 *    - 会被嵌入父窗口的布局中，**默认无窗口边框和标题栏**；
 *    - 适用于控件、面板等场景。
 *
 * 3. 也可作为**独立顶级窗口**使用：
 *    - 不设置 parent；
 *    - 会显示为带有系统边框和标题栏的普通窗口；
 *    - 适用于工具窗口、自定义主窗口等。
 *
 * 4. 是否显示边框由其是否是“顶级窗口”决定（即 parent 是否为 nullptr）。
 */
TestForm::TestForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestForm)
{
    ui->setupUi(this);
}

TestForm::~TestForm()
{
    delete ui;
}
