#ifndef DATATYPES_H
#define DATATYPES_H

#include <QDateTime>
#include <QList>

class Value
{
public:
    int value;
    int source;
    QDateTime datetime;
};

typedef QList<Value> Values;

class Range
{
public:
    QDateTime begin;
    QDateTime end;
};

#endif // DATATYPES_H
