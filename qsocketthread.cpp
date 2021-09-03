#include "qsocketthread.h"

QSocketThread::QSocketThread(int descriptor,QObject *parent)
    : QThread(parent),socketDescriptor(descriptor){}
QSocketThread::~QSocketThread()
{
    delete socket;
}

void QSocketThread::run()
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    qDebug()<<socketDescriptor<< "connection up";
        connect(socket,SIGNAL(readyRead()),this,SLOT(socketReady()),Qt::DirectConnection);
        connect(socket,SIGNAL(disconnected()),this,SLOT(disconnect()),Qt::DirectConnection);
    sender();
    exec();
    qDebug()<<socketDescriptor<<" thread ended";

}

void QSocketThread::sender()
{
    if(socket->isOpen()){
        //генерируем случайное целочисленное значение 1..100 и отправляем клиенту
        socket->write(QByteArray::number(rand()%101));
        //Задержка для чтения клиентом(частота отправки сообщений)
        socket->waitForReadyRead(1000);
        //Рекурсия
        sender();
    }
}

void QSocketThread::socketReady()
{
    //Если клиент что-то таки отправит - обрабатываем тут
}

//При отключении клиента
void QSocketThread::disconnect()
{
    qDebug()<<socketDescriptor<<" connection down";
    socket->close();
    //выход из потока
    quit();
}
