#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QThreadPool>


class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void StartServer();

signals:

public slots:
    void newConnection();

private:
    QThreadPool *pool;
};

#endif // SERVER_H
