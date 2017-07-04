#include "statusthreadcontroller.h"
#include "status.h"
#include "debug.h"

StatusThreadController::StatusThreadController(QObject *parent)
    : QObject(parent)
    , _thread(new QThread(this))
    , _status(new Status())
{
    LOG;
    this->_status->moveToThread(this->_thread);
    connect(this, SIGNAL(generated(Value,int)), this->_status, SLOT(generated(Value,int)));
    connect(this, SIGNAL(written(Value,int)), this->_status, SLOT(written(Value,int)));
    connect(this->_status, SIGNAL(updated(int,int)), this, SIGNAL(updated(int,int)));
    this->_thread->start();
}

StatusThreadController::~StatusThreadController()
{
    this->_status->deleteLater();

    this->_thread->quit();
    this->_thread->wait();
    LOG;
}
