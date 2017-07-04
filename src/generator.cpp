#include "generator.h"
#include "datatypes.h"
#include "debug.h"
#include <QTimerEvent>

#define DEFAULT_FREQUENCY 50
#define MSEC_IN_SEC 1000

int nextSourceId()
{
    static int result = -1;
    return ++result;
}

Generator::Generator(QObject *parent)
    : QObject(parent)
    , _sourceId(nextSourceId())
    , _frequency(0)
    , _timerId(0)
    , _count(0)
{
    LOG << this->_sourceId;
    this->setFrequency(DEFAULT_FREQUENCY);
}

Generator::~Generator()
{
    LOG << this->_sourceId << this->_count;
}

void Generator::setFrequency(int value)
{
    if (this->_frequency != value) {
        if (this->_frequency) {
            if (this->_timerId) {
                this->killTimer(this->_timerId);
                this->_timerId = 0;
            }
        }
        this->_frequency = value;
        if (this->_frequency) {
            this->_timerId = this->startTimer(MSEC_IN_SEC / this->_frequency, Qt::PreciseTimer);
        }
    }
}

void Generator::timerEvent(QTimerEvent* event)
{
    if (event && event->timerId() == this->_timerId) {
        if (!this->_count++) {
            qsrand(QDateTime::currentDateTime().addDays(this->_sourceId).toTime_t());
        }
        const Value value({qrand(), this->_sourceId, QDateTime::currentDateTime()});
        emit this->generated(value, this->_count);
    }
}
