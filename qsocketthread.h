#ifndef QSOCKETTHREAD_H
#define QSOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>

class QSocketThread : public QThread
{
    Q_OBJECT
public:
    explicit QSocketThread(int  descriptor,QObject *parent = nullptr);
    ~QSocketThread();
    void run();
    void sender();
private:
    int socketDescriptor;
    QTcpSocket *socket;

public slots:
    void socketReady();
    void disconnect();
};

#endif // QSOCKETTHREAD_H
