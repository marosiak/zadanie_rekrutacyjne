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
    QXmlStreamAttributes requestAtr;
    QXmlStreamAttributes dataAtr;
    while (!reader.atEnd()) {
        if(reader.name() == "data"){
            dataAtr = reader.attributes();
        }
        if(reader.name() == "request"){
            requestAtr = reader.attributes();
        }
        reader.readNext();
    }
    QString login, password;
    if(dataAtr.size() >= 1){
        qDebug() << "D"<<dataAtr.at(0).name();
        if(dataAtr.at(0).name() == "login"){
            qDebug() << "SHIT";
            login = dataAtr.at(0).value().toString();
        }
        if(dataAtr.at(1).name() == "password"){
            password = dataAtr.at(1).value().toString();
        }
    }
    qDebug() << login << password;
    if(requestAtr.size() >= 1){
        if(requestAtr.at(0).name() == "type"){
            if(requestAtr.at(0).value() == "login"){
                qDebug() << "handling login";
                // check if correct
                if(accountsTable->login(new Account(login, password))){
                    qDebug() << "success login";
                    ResponseGenerator rpg(LoginSuccess);
                    socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
                } else {
                    // failed
                    ResponseGenerator rpg(LoginFailed);
                    socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
                }
            }
        }
        if(requestAtr.at(0).value() == "register"){
            qDebug() << "handling register";
            if(accountsTable->addAccount(new Account(login, password))){
                // success
                qDebug() << "success register";
                ResponseGenerator rpg(RegisterSuccess);
                socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
            } else {
                // failed
                ResponseGenerator rpg(RegisterFailed);
                socket->write(QByteArray::fromStdString(rpg.getOutput().toStdString()));
            }
        }
    }
}

void ConnectionHandler::disconnected() {
    qDebug() << socketDescriptor << "Disconnected\n";
    socket->deleteLater();
    exit(0);
}
