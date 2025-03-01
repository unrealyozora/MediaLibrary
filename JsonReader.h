#ifndef JSON_READER_H
#define JSON_READER_H
#include <AbstractItem.h>
#include <qjsonobject.h>
class JsonReader {
public:
	AbstractItem* readMovie(QJsonObject& obj) const ;
};
#endif
