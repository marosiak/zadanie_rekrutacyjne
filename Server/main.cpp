#include <QCoreApplication>
#include <Server/server.h>


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Server srv;
    srv.startServer(2222);


    return a.exec();
}
