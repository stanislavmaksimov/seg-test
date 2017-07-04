#include "storage.h"
#include "debug.h"

QDataStream &operator<<(QDataStream& stream, const Value& value)
{
    stream << value.datetime << value.value;
    return stream;
}

QDataStream &operator>>(QDataStream& stream, Value& value)
{
    stream >> value.datetime >> value.value;
    return stream;
}

Storage::Storage(QObject* parent)
    : QObject(parent)
    , _lock()
    , _file()
    , _fileStream(&this->_file)
    , _fileIsOpened(this->_file.open())
    , _written(0)
{
    LOG << this->_file.fileName();
}

Storage::~Storage()
{
    LOG << this->_file.fileName() << this->_written;
}

void Storage::write(const Value& value)
{
    if (this->_fileIsOpened) {

        QWriteLocker locker(&this->_lock);
        Q_UNUSED(locker);

        this->_fileStream << value;
        this->_file.flush();
        ++this->_written;

        emit this->written(value, this->_written);
    }
}

Values Storage::read(const Range& range)
{
    LOG;

    QReadLocker locker(&this->_lock);
    Q_UNUSED(locker);

    QList<Value> result;
    QFile file(this->_file.fileName());
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);
        Value value;
        while (!stream.atEnd()) {
            stream >> value;
            if (!range.begin.isValid() || range.begin <= value.datetime) {
                if (!range.end.isValid() || range.end >= value.datetime) {
                    result.push_back(value);
                }
            }
        }
    }

    qSort(result.begin(), result.end(), [](const Value& l, const Value& r)->bool{
        if (l.datetime != r.datetime) return l.datetime < r.datetime;
        if (l.source != r.source) return l.source < r.source;
        return l.value < r.value;
    });
    LOG << result.count();

    return result;
}
