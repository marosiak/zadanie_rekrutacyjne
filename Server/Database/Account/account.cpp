#include "account.h"

Account::Account(QString login, QString password){
    setLogin(login);
    setPassword(password);
}

QString Account::login() const { return m_login; }
QString Account::password() const { return m_password; }

void Account::setLogin(const QString &login) { m_login = login; }
void Account::setPassword(const QString &password) { m_password = password; }
