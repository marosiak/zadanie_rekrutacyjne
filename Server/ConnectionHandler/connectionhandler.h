#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class ConnectionHandler : public QThread {
    Q_OBJECT
public:
    explicit ConnectionHandler(qintptr id, QObject *parent = 0);
    void run();

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // CONNECTIONHANDLER_H
