#include "JsonReader.h"
#include <memory>
std::shared_ptr<Movie> JsonReader::readMovie(QJsonObject& obj)  {
	return std::make_shared<Movie>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(),
			obj["director"].toString().toStdString(), obj["screenwriter"].toString().toStdString(), obj["length"].toInt(), obj["production_comp"].toString().toStdString());
}

std::shared_ptr<Album> JsonReader::readAlbum(QJsonObject &obj) {
    return std::make_shared<Album>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(),obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(),
			obj["author"].toString().toStdString(), obj["songs"].toInt(), obj["length"].toInt());
}

std::shared_ptr<Videogames> JsonReader::readVideogame(QJsonObject &obj){
    return std::make_shared<Videogames>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(),
            obj["developer"].toString().toStdString(), obj["multiplayer"].toBool());
}

std::shared_ptr<Comic> JsonReader::readComic(QJsonObject &obj) {
    return std::make_shared<Comic>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(),
			obj["author"].toString().toStdString(), obj["chapters"].toInt());
}

std::shared_ptr<Books> JsonReader::readBooks(QJsonObject &obj) {
    return std::make_shared<Books>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(),
			obj["author"].toString().toStdString(), obj["pages"].toInt(), obj["publ"].toString().toStdString());
}
