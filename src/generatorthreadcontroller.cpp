#include "generatorthreadcontroller.h"
#include "generator.h"
#include "debug.h"

GeneratorThreadController::GeneratorThreadController(QObject *parent)
    : QObject(parent)
    , _thread(new QThread(this))
    , _generator(new Generator())
{
    LOG;
    this->_generator->moveToThread(this->_thread);
    connect(this->_generator, &Generator::generated, this, &GeneratorThreadController::generated);
    this->_thread->start();
}

GeneratorThreadController::~GeneratorThreadController()
{
    this->_generator->deleteLater();

    this->_thread->quit();
    this->_thread->wait();
    LOG;
}

void GeneratorThreadController::setFrequencyAsync(int value)
{
    QMetaObject::invokeMethod(this->_generator, "setFrequency", Qt::QueuedConnection, Q_ARG(int, value));
}
