#include "auth.h"

Auth::Auth(QObject *parent) : QObject(parent){
    socket = new QTcpSocket;
}

bool Auth::doAuth(QString login, QString password){
    socket->connectToHost(host,port);
    if(socket->waitForConnected(500)){
        RequestGenerator rg;
        socket->write(QByteArray::fromStdString(rg.login(login, password).toStdString()));
        socket->waitForBytesWritten(500);
        socket->waitForReadyRead(500);
        QXmlStreamReader reader(socket->readAll());
        QString type;
        while(!reader.atEnd()){
            if(reader.name() == "response"){
                foreach(QXmlStreamAttribute att, reader.attributes()){
                    if(att.name() == "type"){
                        type = att.value().toString();
                    }
                }
            }
            if(reader.name() == "info"){
                foreach(QXmlStreamAttribute att, reader.attributes()){
                    if(att.name() == "info"){
                        if(type == "success"){
                            socket->disconnect();
                            return true;
                        } else {
                            info = att.value().toString();
                            socket->disconnect();
                            return false;
                        }
                    }
                }
            }
            reader.readNext();
        }

        socket->disconnect();

    } else {
        info = "Time out";
        return false;
    }
}

bool Auth::register_(QString login, QString password){
    socket->connectToHost(host,port);
    if(socket->waitForConnected(500)){
        RequestGenerator rg;
        socket->write(QByteArray::fromStdString(rg.register_(login, password).toStdString()));
        socket->waitForBytesWritten(500);
        socket->waitForReadyRead(500);
        QXmlStreamReader reader(socket->readAll());
        QString type;
        while(!reader.atEnd()){
            if(reader.name() == "response"){
                foreach(QXmlStreamAttribute att, reader.attributes()){
                    if(att.name() == "type"){
                        type = att.value().toString();
                    }
                }
            }
            if(reader.name() == "info"){
                foreach(QXmlStreamAttribute att, reader.attributes()){
                    if(att.name() == "info"){
                        if(type == "success"){
                            socket->disconnect();
                            return true;
                        } else {
                            info = att.value().toString();
                            socket->disconnect();
                            return false;
                        }
                    }
                }
            }
            reader.readNext();
        }

        socket->disconnect();

    } else {
        info = "Time out";
        return false;
    }
}

void Auth::setHost(const QString &value){
    host = value;
}

void Auth::setPort(const int &value){
    port = value;
}

QString Auth::getInfo() const{
    return info;
}
