#include <QCoreApplication>
#include <Server/server.h>


// only for test
#include <Database/DatabaseAccess/databaseaccess.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Server srv;
    srv.startServer(2222);

    // test only
    DatabaseAccess dba;
    dba.connect("127.0.0.1", "rekrutacja", "postgres", "admin");
    dba.execute("CREATE TABLE IF NOT EXISTS accounts(login \"char\"[], password \"char\"[])");
    return a.exec();
}
