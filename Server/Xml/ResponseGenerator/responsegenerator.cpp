#include "responsegenerator.h"

ResponseGenerator::ResponseGenerator(Response type){
    m_type = type;
}

QString ResponseGenerator::getOutput(){
    QDomDocument document;
    QDomElement root = document.createElement("response");
    QDomElement el = document.createElement("info");

    switch(m_type){
    case RegisterSuccess:
        el.setAttribute("info", "Account created successfully");
        break;
    case LoginSuccess:
        el.setAttribute("info", "Logged in");
        break;
    case RegisterFailed:
        el.setAttribute("info", "You are unable to create account");
        break;
    case LoginFailed:
        el.setAttribute("info", "Cannot log-in");
        break;
    default:
        el.setAttribute("info", "Error");
        break;
    }
    if(m_type == LoginFailed || RegisterFailed){
        root.setAttribute("type", "failed");
    }
    if(m_type == LoginSuccess || RegisterSuccess){
        root.setAttribute("type", "success");
    }
    root.appendChild(el);
    document.appendChild(root);

    return document.toString();
}

void ResponseGenerator::setType(const Response &type){ m_type = type; }
Response ResponseGenerator::type() const { return m_type; }
