#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent) {
    dba = new DatabaseAccess;
    dba->connect("127.0.0.1", "rekrutacja", "postgres", "admin");
    accounts = new AccountsTable(dba);
}

void Server::startServer(int port){

    if(!this->listen(QHostAddress::Any,port)) {
        qDebug() << "Could not start server";
    }
    else {
        qDebug() << "Listening to port" << port << "\n\n";
    }
}

void Server::incomingConnection(qintptr socketDescriptor){
    qDebug() << socketDescriptor << "Connecting...";

    ConnectionHandler *thread = new ConnectionHandler(socketDescriptor, accounts ,this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
