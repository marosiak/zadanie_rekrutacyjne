#include "connectionhandler.h"

ConnectionHandler::ConnectionHandler(qintptr id, QObject *parent) : QThread(parent){
    this->socketDescriptor = id;
}

void ConnectionHandler::run(){
    socket = new QTcpSocket;

    if(!socket->setSocketDescriptor(this->socketDescriptor)) {
        qDebug() << "ERROR connectionHandler.cpp";
        return;
    }
    qDebug() << this->socketDescriptor << "Connected";
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    exec();
}

void ConnectionHandler::readyRead() {
    QByteArray data = socket->readAll();

}

void ConnectionHandler::disconnected() {
    qDebug() << socketDescriptor << "Disconnected\n";
    socket->deleteLater();
    exit(0);
}
