#include "responsegenerator.h"

ResponseGenerator::ResponseGenerator(bool succ, QString in){
    setInfo(in);
    setSuccess(succ);
}

QString ResponseGenerator::getOutput(){
    QDomDocument document;
    QDomElement root = document.createElement("response");
    QDomElement el = document.createElement("info");

    el.setAttribute("info", getInfo());
    if(getSuccess()){
        root.setAttribute("type", "success");
    } else {
        root.setAttribute("type", "failed");
    }
    root.appendChild(el);
    document.appendChild(root);

    return document.toString();
}

bool ResponseGenerator::getSuccess() const
{
    return success;
}

void ResponseGenerator::setSuccess(bool value)
{
    success = value;
}

QString ResponseGenerator::getInfo() const
{
    return info;
}

void ResponseGenerator::setInfo(const QString &value)
{
    info = value;
}
