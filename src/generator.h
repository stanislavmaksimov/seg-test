#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>

class Value;

class Generator : public QObject
{
    Q_OBJECT

    const int _sourceId;
    int _frequency; //values per second
    int _timerId;
    int _count;

signals:
    void generated(const Value& value, int count);

public:
    explicit Generator(QObject *parent = nullptr);
    virtual ~Generator();

public slots:
    void setFrequency(int = 0);

protected:
    void timerEvent(QTimerEvent*);
};

#endif // GENERATOR_H
