#ifndef RESPONSEGENERATOR_H
#define RESPONSEGENERATOR_H

#include <QString>
#include <QtXml>

enum Response {
    LoginSuccess,
    LoginFailed,
    RegisterSuccess,
    RegisterFailed
};

class ResponseGenerator {
public:
    ResponseGenerator(Response type);
    ResponseGenerator();

    QString getOutput();
    void setType(const Response &type);
    Response type() const;

private:
    Response m_type;
};

#endif // RESPONSEGENERATOR_H
