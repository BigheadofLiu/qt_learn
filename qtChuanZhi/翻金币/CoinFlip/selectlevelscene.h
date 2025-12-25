#ifndef SELECTLEVELSCENE_H
#define SELECTLEVELSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QLabel>

#include "mypushbtn.h"
#include "playscene.h"

namespace Ui {
class SelectLevelScene;
}

class SelectLevelScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectLevelScene(QWidget *parent = nullptr);
    ~SelectLevelScene();
    void paintEvent(QPaintEvent *event) override;
signals:
    void selectSceneBack();
private:
    Ui::SelectLevelScene *ui;
    PlayScene* mPlayScene=nullptr;
};

#endif // SELECTLEVELSCENE_H
