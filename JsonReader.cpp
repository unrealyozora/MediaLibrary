#include "JsonReader.h"
#include <memory>
std::shared_ptr<Movie> JsonReader::readMovie(QJsonObject& obj)  {
	return std::make_shared<Movie>
		(obj["title"].toString(), obj["year"].toString(), obj["description"].toString(),obj["genre"].toArray(), obj["country"].toString(), 
			obj["director"].toString(), obj["screenwriter"].toString(), obj["length"].toInt(), obj["production_comp"].toString()); //sono sicuro del metodo toInt()
}

std::shared_ptr<Album> JsonReader::readAlbum(QJsonObject &obj) {
    return std::make_shared<Album>
		(obj["title"].toString(), obj["year"].toString(), obj["description"].toString(),obj["genre"].toArray(), obj["country"].toString(),
			obj["author"].toString(), obj["songs"].toInt(), obj["length"].toInt());
}

std::shared_ptr<Videogames> JsonReader::readVideogame(QJsonObject &obj){
    return std::make_shared<Videogames>
		(obj["title"].toString(), obj["year"].toString(), obj["description"].toArray(), obj["genre"].toArray(), obj["country"].toString(),
            obj["developer"].toString(), obj["multiplayer"].toBool()); // non sono sicuro esista il metodo toBool, non posso controllarlo al momento
}

std::shared_ptr<Comic> JsonReader::readComic(QJsonObject &obj) {
    return std::make_shared<Comic>
		(obj["title"].toString(), obj["year"].toString(), obj["description"].toArray(), obj["genre"].toArray(), obj["country"].toString(),
			obj["author"].toString(), obj["chapters"].toInt());//non sono sicuro esista il metodo toInt, non posso controllarlo al momento
}

std::shared_ptr<Books> JsonReader::readBooks(QJsonObject &obj) {
    return std::make_shared<Books>
		(obj["title"].toString(), obj["year"].toString(), obj["description"].toArray(), obj["genre"].toArray(), obj["country"].toString(),
			obj["author"].toString(), obj["pages"].toInt(), obj["publ"].toString()); // stesso problema di prima, non sono sicuro esista toInt()
}
