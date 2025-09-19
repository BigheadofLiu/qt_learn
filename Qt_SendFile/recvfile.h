#ifndef RECVFILE_H
#define RECVFILE_H

#include <QObject>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

class recvFile : public QThread
{
    Q_OBJECT
public:
    explicit recvFile(QObject *parent = nullptr);
public slots:
    void setTcpSocket(QTcpSocket* client);
signals:
    void sendOver();
protected:
    void run() override;
private:
    QTcpSocket* mClient;
};

#endif // RECVFILE_H
