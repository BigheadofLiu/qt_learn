#ifndef ME_H
#define ME_H

#include <QObject>

class Me : public QObject
{
    Q_OBJECT
public:
    explicit Me(QObject *parent = nullptr);
public slots:
    void eat();
    void eat(QString msg);
signals:

};

#endif // ME_H
