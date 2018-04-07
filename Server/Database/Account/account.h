#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account {
public:
    Account(QString login, QString password);
    QString login() const;
    void setLogin(const QString &login);

    QString password() const;
    void setPassword(const QString &password);

private:
    QString m_login;
    QString m_password;
};

#endif // ACCOUNT_H
