#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QTimer>
#include <QLabel>

#include "mypushbtn.h"
#include "mycoin.h"

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
    int mLevel;
};

#endif // PLAYSCENE_H
