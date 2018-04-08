#ifndef AUTH_H
#define AUTH_H

#include <QObject>
#include <QTcpSocket>
#include <Xml/RequestGenerator/requestgenerator.h>

class Auth : public QObject{
    Q_OBJECT
public:
    explicit Auth(QObject *parent = nullptr);
    void setHost(const QString &value);
    void setPort(const int &value);

signals:

private:
    QTcpSocket* socket;
    QString host;
    int port;
    QString info;
public slots:
    bool doAuth(QString login, QString password);
    bool register_(QString login, QString password);
    QString getInfo() const;
};

#endif // AUTH_H
