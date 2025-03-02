#include "JsonReader.h"
#include <movie.h>
#include <memory>
std::shared_ptr<AbstractItem> JsonReader::readMovie(QJsonObject& obj)  {
	return std::make_shared<AbstractItem>
		(obj["title"].toString(), obj["year"].toString(), obj["description"].toArray(),obj["genre"].toArray(), obj["country"].toString(), 
			obj["director"].toString(), obj["screenwriter"].toString(), obj["length"].toString(), obj["production_comp"].toString());
}
