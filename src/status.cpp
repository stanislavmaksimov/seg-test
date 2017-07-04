#include "status.h"
#include "debug.h"
#include "datatypes.h"
#include <QTimerEvent>

Status::Status(QObject *parent)
    : QObject(parent)
    , _timerId(this->startTimer(50))
    , _generated()
    , _written(0)
    , _writtenPrev(0)
    , _generatedPrev(0)
{
    LOG;
    this->update();
}

Status::~Status()
{
    LOG;
}

void Status::generated(const Value& value, int count)
{
    this->_generated.insert(value.source, count);
}

void Status::written(const Value&, int count)
{
    this->_written = count;
}

void Status::update()
{
    int generatedTotal = 0;
    const auto generatedValues = this->_generated.values();
    for (auto generatedValue: generatedValues) generatedTotal += generatedValue;
    this->update(generatedTotal, this->_written);
}

void Status::update(int generated, int written)
{
    if (this->_generatedPrev != generated || this->_writtenPrev != written) {
        this->_generatedPrev = generated;
        this->_writtenPrev = written;
        this->updated(this->_generatedPrev, this->_writtenPrev);
    }
}

void Status::timerEvent(QTimerEvent* event)
{
    if (event && event->timerId() == this->_timerId) {
        this->update();
    }
}
