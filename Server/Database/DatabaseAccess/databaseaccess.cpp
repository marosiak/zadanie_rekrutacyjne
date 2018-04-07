#include "databaseaccess.h"

DatabaseAccess::DatabaseAccess(QObject *parent) : QObject(parent){
    QSqlDatabase d = QSqlDatabase::addDatabase("QPSQL");
    database = new QSqlDatabase(d);
}

DatabaseAccess::~DatabaseAccess(){
    database->close();
}


bool DatabaseAccess::connect( const QString& server,
                                     const QString& databaseName,
                                     const QString& userName,
                                     const QString& password ) {
    database->setConnectOptions();
    database->setHostName(server);
    database->setDatabaseName(databaseName);
    database->setUserName(userName);
    database->setPassword(password);

    if(database->open()) {
        return true;
    }
    else {
        return false;
    }
}

QSqlQuery DatabaseAccess::execute(QString query){
    return database->exec(query);
}
