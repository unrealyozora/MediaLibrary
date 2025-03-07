#ifndef JSON_WRITER_H
#define JSON_WRITER_H
#include <memory>
#include <qlist.h>
#include "../items/AbstractItem.h"
#include "JsonVisitor.h"
class JsonWriter{
public:
	static void writeJson(const QString& path, const QList<std::shared_ptr<AbstractItem>>& media);
};
#endif