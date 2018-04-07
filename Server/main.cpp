#include <QCoreApplication>
#include <Server/server.h>

// test only
#include <Xml/ResponseGenerator/responsegenerator.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Server srv;
    srv.startServer(2222);

    ResponseGenerator rg(LoginFailed);
    qDebug() << rg.getOutput();


    return a.exec();
}
