#ifndef DATABASEACCESS_H
#define DATABASEACCESS_H

#include <QObject>
#include <QtSql>

class DatabaseAccess : public QObject {
    Q_OBJECT
public:
    explicit DatabaseAccess(QObject *parent = nullptr);
    ~DatabaseAccess();
    bool connect(const QString &server, const QString &databaseName, const QString &userName, const QString &password);
    QSqlQuery execute(QString query);
signals:

private:
    QSqlDatabase* database;
};

#endif // DATABASEACCESS_H
