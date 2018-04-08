#ifndef REQUESTGENERATOR_H
#define REQUESTGENERATOR_H

#include <QString>
#include <QtXml>

class RequestGenerator {

public:
    RequestGenerator();
    QString login(QString login, QString password);
    QString register_(QString login, QString password);
};

#endif // REQUESTGENERATOR_H
