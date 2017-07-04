#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "generatorthreadcontroller.h"
#include "storagethreadcontroller.h"
#include "statusthreadcontroller.h"
#include "datatypes.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<Value>("Value");
    qRegisterMetaType<Values>("Values");
    qRegisterMetaType<Range>("Range");

    qmlRegisterType<GeneratorThreadController>("GeneratorThreadController", 1, 0, "GeneratorThreadController");
    qmlRegisterType<StorageThreadController>("StorageThreadController", 1, 0, "StorageThreadController");
    qmlRegisterType<StatusThreadController>("StatusThreadController", 1, 0, "StatusThreadController");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine(&app);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec(); StatusThreadController();
}
