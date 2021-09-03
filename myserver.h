#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "qsocketthread.h"

class MyServer: public QTcpServer
{
    Q_OBJECT

public:
    MyServer();
    ~MyServer();

private:
    QByteArray Data;
public slots:
    //Метод по умолчанию для TcpServer содержит описание действий в случае подключения нового клиента
    //SocketDescriptor - id соединения
    void incomingConnection(int socketDescriptor);
};

#endif // MYSERVER_H
