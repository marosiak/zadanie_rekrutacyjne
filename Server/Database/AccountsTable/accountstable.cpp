#include "accountstable.h"

AccountsTable::AccountsTable(DatabaseAccess *databaseAccess){
    m_databaseAccess = databaseAccess;
    m_databaseAccess->execute("CREATE TABLE IF NOT EXISTS accounts(login text, password text)");
}

bool AccountsTable::addAccount(Account *acc){
    if(accountExists(acc->login()) == true){
        return false;
    }
    QSqlQuery q = m_databaseAccess->execute(QString("INSERT INTO public.accounts"
                                                    "(login, password) "
                                                    "VALUES ('%1', '%2')")
                                            .arg(acc->login())
                                            .arg(acc->password()));
    return q.isValid();
}

bool AccountsTable::accountExists(QString login){
    QSqlQuery query = m_databaseAccess->execute(QString("SELECT * FROM public.accounts WHERE login='%1'").arg(login));
    while (query.next()) {
        return true;
    }
    return false;
}

bool AccountsTable::login(Account *acc){
    QSqlQuery query = m_databaseAccess->execute(QString("SELECT * FROM public.accounts WHERE login='%1' AND password='%2'")
                                                .arg(acc->login())
                                                .arg(acc->password()));
    while (query.next()) {
        return true;
    }
    return false;
}
