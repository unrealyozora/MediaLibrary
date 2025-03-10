#ifndef JSON_READER_H
#define JSON_READER_H
#include "../items/AbstractItem.h"
#include <memory>
#include <qjsonobject.h>
#include <qjsonarray.h>
#include "../items/movie.h"
#include "../items/Videogames.h"
#include "../items/Comic.h"
#include "../items/Books.h"
#include "../items/album.h"
class JsonReader {
public:
	static std::shared_ptr<Movie> readMovie(QJsonObject& obj);
	static std::shared_ptr<Album> readAlbum(QJsonObject& obj);
	static std::shared_ptr<Videogames> readVideogame(QJsonObject& obj);
	static std::shared_ptr<Comic> readComic(QJsonObject& obj);
	static std::shared_ptr<Books> readBooks(QJsonObject& obj);
};
#endif
