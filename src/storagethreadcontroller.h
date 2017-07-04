#ifndef STORAGETHREADCONTROLLER_H
#define STORAGETHREADCONTROLLER_H

#include <QObject>

class QThread;
class Storage;
class Value;
class Range;

class StorageThreadController : public QObject
{
    Q_OBJECT

    QThread* const _thread;
    Storage* const _storage;

signals:
    void write(const Value& value, int count);
    void written(const Value& value, int count);

public:
    explicit StorageThreadController(QObject *parent = nullptr);
    virtual ~StorageThreadController();

public slots:
    void readAllAsync();
};

#endif // STORAGETHREADCONTROLLER_H
