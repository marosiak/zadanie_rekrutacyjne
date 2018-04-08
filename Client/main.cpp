#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Auth/auth.h>
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Auth auth;
    auth.setHost("127.0.0.1");
    auth.setPort(2222);
    QQmlContext * ctx = engine.rootContext();
    ctx->setContextProperty("auth", &auth);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
