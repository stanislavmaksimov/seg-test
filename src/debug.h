#ifndef DEBUG_H
#define DEBUG_H

#include <QDebug>
#include <QThread>

#define LOG qDebug() << QThread::currentThreadId() << __FUNCTION__

#endif // DEBUG_H
