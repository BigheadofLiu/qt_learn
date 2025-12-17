#include "testdialog.h"
#include "ui_testdialog.h"

/**
 * QDialog —— 对话框窗体类（继承自 QWidget）
 *
 * 1. QDialog 用于创建对话框窗口，适合弹出式交互场景（如设置、提示、输入等）。
 *
 * 2. 支持两种显示方式：
 *    a. 模态（Modal）：
 *       - 阻塞当前窗口的输入；
 *       - 常用函数：exec()；
 *       - 使用场景：用户必须完成该对话框的操作后才能继续其他窗口。
 *
 *    b. 非模态（Modeless）：
 *       - 不阻塞当前窗口；
 *       - 常用函数：show()；
 *       - 使用场景：工具窗口、辅助面板等。
 *
 * 3. 不支持作为子控件嵌入到其他窗口（无法内嵌到布局中）。
 *    - QDialog 是独立窗口，默认带有窗口边框和标题栏；
 *    - 如果需要可嵌入的界面，请使用 QWidget 或 QFrame。
 */

TestDialog::TestDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TestDialog)
{
    ui->setupUi(this);
}

TestDialog::~TestDialog()
{
    delete ui;
}
