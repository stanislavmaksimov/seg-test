#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QDataStream>
#include <QReadWriteLock>
#include <QTemporaryFile>
#include "datatypes.h"

class Storage : public QObject
{
    Q_OBJECT

    QReadWriteLock _lock;
    QTemporaryFile _file;
    QDataStream _fileStream;
    const bool _fileIsOpened;
    int _written;

signals:
    void written(const Value& value, int count);

public:
    explicit Storage(QObject *parent = nullptr);
    virtual ~Storage();

public slots:
    void write(const Value&);
    Values read(const Range& range = Range());
};

#endif // STORAGE_H
