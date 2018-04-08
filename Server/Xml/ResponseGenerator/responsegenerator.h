#ifndef RESPONSEGENERATOR_H
#define RESPONSEGENERATOR_H

#include <QString>
#include <QtXml>

class ResponseGenerator {
public:
    ResponseGenerator(bool succ, QString in);
    ResponseGenerator();

    QString getOutput();


    bool getSuccess() const;
    void setSuccess(bool value);

    QString getInfo() const;
    void setInfo(const QString &value);

private:
    bool success=false;
    QString info="error";
};

#endif // RESPONSEGENERATOR_H
