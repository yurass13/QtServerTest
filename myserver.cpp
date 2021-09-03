#include "myserver.h"
#include <math.h>

MyServer::MyServer()
{
    //Попытка запустить сервер и начать слушать порт 80 с ЛЮБЫХ адресов
    if(this->listen(QHostAddress::Any,80)){
        qDebug()<<"Listening!";
    }
    else{
        qDebug()<<"Try to up server was faild";
    }
}
MyServer::~MyServer(){}


//переопределение виртуальной функции TcpServer::incomingConnection(int socketDescriptor)
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<socketDescriptor<< "new connection";
    QSocketThread *thread = new QSocketThread(socketDescriptor);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
    qDebug()<<socketDescriptor<<" thread started";
}
