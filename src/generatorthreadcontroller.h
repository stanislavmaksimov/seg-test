#ifndef GENERATORTHREADCONTROLLER_H
#define GENERATORTHREADCONTROLLER_H

#include <QObject>

class QThread;
class Generator;
class Value;

class GeneratorThreadController : public QObject
{
    Q_OBJECT

    QThread* const _thread;
    Generator* const _generator;

signals:
    void generated(const Value& value, int count);

public:
    explicit GeneratorThreadController(QObject *parent = nullptr);
    virtual ~GeneratorThreadController();

public slots:
    void setFrequencyAsync(int);
};

#endif // GENERATORTHREADCONTROLLER_H
