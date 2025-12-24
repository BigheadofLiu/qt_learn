#ifndef SELECTLEVELSCENE_H
#define SELECTLEVELSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

#include "mypushbtn.h"

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
};

#endif // SELECTLEVELSCENE_H
