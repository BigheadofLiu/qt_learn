#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QTimer>
#include <QLabel>
#include <QSoundEffect>

#include "mypushbtn.h"
#include "mycoin.h"
#include "dataconfig.h"

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayScene(QWidget *parent = nullptr);
    ~PlayScene();
    PlayScene(int level);
    void paintEvent(QPaintEvent *event) override;
signals:
    void playSceneBack();
private:
    Ui::PlayScene *ui;
    int mLevel;         //游戏等级
    int mGameArry[4][4];  //用于读取关卡数据  初始化金币状态
    MyCoin* mIconBtnArry[4][4];  //记录金币按钮状态 用于判断是否胜利
    bool mIsWin=true;  //是否胜利  胜利标志位
};

#endif // PLAYSCENE_H
