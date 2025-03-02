#ifndef JSON_READER_H
#define JSON_READER_H
#include <AbstractItem.h>
#include <qjsonobject.h>
class JsonReader {
public:
	static std::shared_ptr<AbstractItem> readMovie(QJsonObject& obj) ;
};
#endif
