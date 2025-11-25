#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>

class sendFile : public QObject
{
    Q_OBJECT
public:
    explicit sendFile(QObject *parent = nullptr);
    void connectServer(QString ip,unsigned short port);
    void fileSend(QString filePath);
signals:
    void isConnected();
    void disConnected();
    void curPercent(int percent);
private:
    QTcpSocket* mClient=nullptr;
};

#endif // SENDFILE_H
