#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent) {
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

    ConnectionHandler *thread = new ConnectionHandler(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
