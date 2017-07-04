#include "storagethreadcontroller.h"
#include "storage.h"
#include "debug.h"

StorageThreadController::StorageThreadController(QObject *parent)
    : QObject(parent)
    , _thread(new QThread(this))
    , _storage(new Storage())
{
    LOG;
    this->_storage->moveToThread(this->_thread);
    connect(this, SIGNAL(write(Value,int)), this->_storage, SLOT(write(Value)));
    connect(this->_storage, SIGNAL(written(Value,int)), this, SIGNAL(written(Value,int)));
    this->_thread->start();
}

StorageThreadController::~StorageThreadController()
{
    this->_storage->deleteLater();

    this->_thread->quit();
    this->_thread->wait();
    LOG;
}

void StorageThreadController::readAllAsync()
{
    QMetaObject::invokeMethod(this->_storage, "read", Qt::AutoConnection, Q_ARG(Range, Range()));
}
