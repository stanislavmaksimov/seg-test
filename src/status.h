#ifndef STATUS_H
#define STATUS_H

#include <QObject>
#include <QHash>

class Value;

class Status : public QObject
{
    Q_OBJECT

    const int _timerId;
    QHash<int, int> _generated; // counters by source
    int _written;
    int _writtenPrev;
    int _generatedPrev;

signals:
    void updated(int generated, int written);

public:
    explicit Status(QObject *parent = nullptr);
    virtual ~Status();

public slots:
    void generated(const Value& value, int count);
    void written(const Value& value, int count);

protected:
    void timerEvent(QTimerEvent*);

private slots:
    void update();
    void update(int, int);
};

#endif // STATUS_H
