#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QObject>
#include <QDebug>
#include <ConnectionHandler/connectionhandler.h>
#include <Database/DatabaseAccess/databaseaccess.h>
#include <Database/AccountsTable/accountstable.h>
#include <Database/Account/account.h>

class Server : public QTcpServer {
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void startServer(int port);
signals:

private:
    DatabaseAccess* dba;
    AccountsTable* accounts;
protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // SERVER_H
