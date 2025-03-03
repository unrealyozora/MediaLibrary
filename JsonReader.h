#ifndef JSON_READER_H
#define JSON_READER_H
#include <AbstractItem.h>
#include <qjsonobject.h>
#include <movie.h>
#include <Videogames.h>
#include <Comic.h>
#include <Books.h>
#include <album.h>
class JsonReader {
public:
	static std::shared_ptr<Movie> readMovie(QJsonObject& obj) ;
	static std::shared_ptr<Album> readAlbum(QJsonObject& obj) ;
	static std::shared_ptr<Videogames> readVideogame(QJsonObject& obj) ;
	static std::shared_ptr<Comic> readComic(QJsonObject& obj) ;
	static std::shared_ptr<Books> readBooks(QJsonObject& obj) ;
};
#endif
