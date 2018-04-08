#include "accountstable.h"

AccountsTable::AccountsTable(DatabaseAccess *databaseAccess){
    m_databaseAccess = databaseAccess;
    m_databaseAccess->execute("CREATE TABLE IF NOT EXISTS accounts(login text, password text)");
}

bool AccountsTable::addAccount(Account *acc){
    if(accountExists(acc->login()) == true){
        return false;
    }
    QString hash = QCryptographicHash::hash(QByteArray::fromStdString(acc->password().toStdString()), QCryptographicHash::Sha384).toBase64();
    QSqlQuery q = m_databaseAccess->execute(QString("INSERT INTO public.accounts"
                                                    "(login, password) "
                                                    "VALUES ('%1', '%2')")
                                            .arg(acc->login())
                                            .arg(hash));
    return true;
}

bool AccountsTable::accountExists(QString login){
    QSqlQuery query = m_databaseAccess->execute(QString("SELECT * FROM public.accounts WHERE login='%1'").arg(login));
    while (query.next()) {
        return true;
    }
    return false;
}

bool AccountsTable::login(Account *acc){
    QString hash = QCryptographicHash::hash(QByteArray::fromStdString(acc->password().toStdString()), QCryptographicHash::Sha384).toBase64();
    QSqlQuery query = m_databaseAccess->execute(QString("SELECT * FROM public.accounts WHERE login='%1' AND password='%2'")
                                                .arg(acc->login())
                                                .arg(hash));
    while (query.next()) {
        return true;
    }
    return false;
}
