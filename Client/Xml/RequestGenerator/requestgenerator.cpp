#include "requestgenerator.h"

RequestGenerator::RequestGenerator(){

}

QString RequestGenerator::login(QString login, QString password){
    QDomDocument document;
    QDomElement root = document.createElement("request");
    root.setAttribute("type", "login");
    QDomElement el = document.createElement("data");
    el.setAttribute("login", login);
    el.setAttribute("password", password);
    root.appendChild(el);
    document.appendChild(root);

    return document.toString();
}

QString RequestGenerator::register_(QString login, QString password){
    QDomDocument document;
    QDomElement root = document.createElement("request");
    root.setAttribute("type", "register");
    QDomElement el = document.createElement("data");
    el.setAttribute("login", login);
    el.setAttribute("password", password);
    root.appendChild(el);
    document.appendChild(root);

    return document.toString();
}
