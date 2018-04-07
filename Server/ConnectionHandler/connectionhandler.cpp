#include "connectionhandler.h"

ConnectionHandler::ConnectionHandler(qintptr id, AccountsTable *act, QObject *parent) : QThread(parent){
    this->socketDescriptor = id;
    this->accountsTable = act;
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
    //    accountsTable->addAccount(new Account("orzel1244", "password"));

    QXmlStreamReader reader(data);
    //    QXmlStreamAttributes requestAtr;
    QString login, password, type;
    while (!reader.atEnd()) {
        if(reader.name() == "request"){
            foreach (QXmlStreamAttribute att, reader.attributes()) {
                if(att.name() == "type"){
                    type = att.value().toString();
                }
            }
        }
        if(reader.name() == "data"){
            foreach(QXmlStreamAttribute att, reader.attributes()){
                if(att.name() == "login"){
                    login = att.value().toString();
                }
                if(att.name() == "password"){
                    password = att.value().toString();
                }
            }
        }
        reader.readNext();
    }
    if(type == "login"){
        // check if correct
        if(accountsTable->login(new Account(login, password))){
            qDebug() << socketDescriptor<<"success login";
            ResponseGenerator rpg(LoginSuccess);
            socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
        } else {
            // failed
            ResponseGenerator rpg(LoginFailed);
            socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
        }
    }
    if(type == "register"){
        if(accountsTable->addAccount(new Account(login, password))){
            // success
            qDebug() << socketDescriptor<<"success register";
            ResponseGenerator rpg(RegisterSuccess);
            socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
        } else {
            // failed
            ResponseGenerator rpg(RegisterFailed);
            socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
        }
    }
}

void ConnectionHandler::disconnected() {
    qDebug() << socketDescriptor << "Disconnected\n";
    socket->deleteLater();
    exit(0);
}
