#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent){
    pool = new QThreadPool(this);
    pool->setMaxThreadCount(5);
}

void Server::StartServer()
{
    connect(this, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!this->listen(QHostAddress::Any, 8080))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void Server::newConnection()
{
    QTcpSocket *socket = this->nextPendingConnection();
}
