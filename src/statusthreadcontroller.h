#ifndef STATUSTHREADCONTROLLER_H
#define STATUSTHREADCONTROLLER_H

#include <QObject>

class QThread;
class Status;
class Value;

class StatusThreadController : public QObject
{
    Q_OBJECT

    QThread* const _thread;
    Status* const _status;

signals:
    void generated(const Value& value, int count);
    void written(const Value& value, int count);
    void updated(int generated, int written);

public:
    explicit StatusThreadController(QObject *parent = nullptr);
    virtual ~StatusThreadController();
};

#endif // STATUSTHREADCONTROLLER_H
