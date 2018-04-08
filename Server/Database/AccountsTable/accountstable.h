#ifndef ACCOUNTSTABLE_H
#define ACCOUNTSTABLE_H

#include <QObject>
#include <Database/DatabaseAccess/databaseaccess.h>
#include <Database/Account/account.h>
#include <QCryptographicHash>

class AccountsTable {
public:
    AccountsTable(DatabaseAccess* databaseAccess);
    bool addAccount(Account *acc);
    bool accountExists(QString login);
    bool login(Account* acc);
signals:

private:
    DatabaseAccess* m_databaseAccess;
public slots:
};

#endif // ACCOUNTSTABLE_H
