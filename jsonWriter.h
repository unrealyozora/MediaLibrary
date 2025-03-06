#ifndef JSON_WRITER_H
#define JSON_WRITER_H
#include <memory>
#include <qlist.h>
#include <AbstractItem.h>
#include <JsonVisitor.h>
class JsonWriter{
public:
	static void writeJson(const QList <std::shared_ptr<AbstractItem>>& items, const QString& path);
};
#endif