#include "JsonReader.h"
#include <memory>
std::shared_ptr<Movie> JsonReader::readMovie(QJsonObject& obj)  {
	auto item = std::make_shared<Movie>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(), obj["image"].toString().toStdString(),
			obj["director"].toString().toStdString(), obj["screenwriter"].toString().toStdString(), obj["length"].toInt(), obj["production_comp"].toString().toStdString());
	item->setViewCount(obj["view_count"].toInt(0));
	return item;
}

std::shared_ptr<Album> JsonReader::readAlbum(QJsonObject &obj) {
    auto item = std::make_shared<Album>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(),obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(), obj["image"].toString().toStdString(),
			obj["author"].toString().toStdString(), obj["songs"].toInt(), obj["length"].toInt());
	item->setViewCount(obj["view_count"].toInt(0));
	return item;
}

std::shared_ptr<Videogames> JsonReader::readVideogame(QJsonObject &obj){
    auto item = std::make_shared<Videogames>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(), obj["image"].toString().toStdString(),
            obj["developer"].toString().toStdString(), obj["multiplayer"].toBool());
	item->setViewCount(obj["view_count"].toInt(0));
	return item;
}

std::shared_ptr<Comic> JsonReader::readComic(QJsonObject &obj) {
    auto item = std::make_shared<Comic>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(), obj["image"].toString().toStdString(),
			obj["author"].toString().toStdString(), obj["chapters"].toInt());
	item->setViewCount(obj["view_count"].toInt(0));
	return item;
}

std::shared_ptr<Books> JsonReader::readBooks(QJsonObject &obj) {
    auto item = std::make_shared<Books>
		(obj["title"].toString().toStdString(), obj["year"].toInt(), obj["description"].toString().toStdString(), obj["genre"].toString().toStdString(), obj["country"].toString().toStdString(), obj["image"].toString().toStdString(),
			obj["author"].toString().toStdString(), obj["pages"].toInt(), obj["publ"].toString().toStdString());
	item->setViewCount(obj["view_count"].toInt(0));
	return item;
}
