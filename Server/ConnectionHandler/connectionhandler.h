#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <Database/AccountsTable/accountstable.h>
#include <Database/Account/account.h>
#include <QtXml>
#include <Xml/ResponseGenerator/responsegenerator.h>

class ConnectionHandler : public QThread {
    Q_OBJECT
public:
    explicit ConnectionHandler(qintptr id, AccountsTable* act ,QObject *parent = 0);
    void run();

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
    AccountsTable* accountsTable;
};

#endif // CONNECTIONHANDLER_H
