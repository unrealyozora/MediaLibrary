#include "JsonReader.h"
#include <movie.h>
#include <memory>
AbstractItem* JsonReader::readMovie(QJsonObject& obj) const  {
	Movie* movie=new Movie(obj.value("director").toString())
}
