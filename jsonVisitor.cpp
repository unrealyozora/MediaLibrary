#include "jsonVisitor.h"
#include <qjsonobject.h>
QJsonArray JsonVisitor::getArray() const {
    return array;
}

void JsonVisitor::visit(Album& album) {
    QJsonObject album_obj;
    album_obj.insert("title", QJsonValue::fromVariant(album.getTitle().c_str()));
    album_obj.insert("tipo", QJsonValue::fromVariant("Album"));
    album_obj.insert("year", QJsonValue::fromVariant(album.getYear()));
    album_obj.insert("description", QJsonValue::fromVariant(album.getDescription().c_str()));
    album_obj.insert("genre", QJsonValue::fromVariant(album.getGenre().c_str()));
    album_obj.insert("country", QJsonValue::fromVariant(album.getCountry().c_str()));
    album_obj.insert("author", QJsonValue::fromVariant(album.getAuthor().c_str()));
    album_obj.insert("songs", QJsonValue::fromVariant(album.getSongs()));
    album_obj.insert("length", QJsonValue::fromVariant(album.getLength()));
    array.append(album_obj);
}

void JsonVisitor::visit(Books& book) {
    QJsonObject book_obj;
    book_obj.insert("title", QJsonValue::fromVariant(book.getTitle().c_str()));
    book_obj.insert("tipo", QJsonValue::fromVariant("Books"));
    book_obj.insert("year", QJsonValue::fromVariant(book.getYear()));
    book_obj.insert("description", QJsonValue::fromVariant(book.getDescription().c_str()));
    book_obj.insert("genre", QJsonValue::fromVariant(book.getGenre().c_str()));
    book_obj.insert("country", QJsonValue::fromVariant(book.getCountry().c_str()));
    book_obj.insert("author", QJsonValue::fromVariant(book.getAuthor().c_str()));
    book_obj.insert("pages", QJsonValue::fromVariant(book.getPages()));
    book_obj.insert("publ", QJsonValue::fromVariant(book.getPub().c_str()));
    array.append(book_obj);
}

void JsonVisitor::visit(Comic& comic) {
    QJsonObject comic_obj;
    comic_obj.insert("title", QJsonValue::fromVariant(comic.getTitle().c_str()));
    comic_obj.insert("tipo", QJsonValue::fromVariant("Comic"));
    comic_obj.insert("year", QJsonValue::fromVariant(comic.getYear()));
    comic_obj.insert("description", QJsonValue::fromVariant(comic.getDescription().c_str()));
    comic_obj.insert("genre", QJsonValue::fromVariant(comic.getGenre().c_str()));
    comic_obj.insert("country", QJsonValue::fromVariant(comic.getCountry().c_str()));
    comic_obj.insert("author", QJsonValue::fromVariant(comic.getAuthor().c_str()));
    comic_obj.insert("chaoters", QJsonValue::fromVariant(comic.getChapters()));
    array.append(comic_obj);
}

void JsonVisitor::visit(Movie& movie) {
    QJsonObject movie_obj;
    movie_obj.insert("title", QJsonValue::fromVariant(movie.getTitle().c_str()));
    movie_obj.insert("tipo", QJsonValue::fromVariant("Movie"));
    movie_obj.insert("year", QJsonValue::fromVariant(movie.getYear()));
    movie_obj.insert("description", QJsonValue::fromVariant(movie.getDescription().c_str()));
    movie_obj.insert("genre", QJsonValue::fromVariant(movie.getGenre().c_str()));
    movie_obj.insert("country", QJsonValue::fromVariant(movie.getCountry().c_str()));
    movie_obj.insert("director", QJsonValue::fromVariant(movie.getDirector().c_str()));
    movie_obj.insert("screenwriter", QJsonValue::fromVariant(movie.getScreenwriter().c_str()));
    movie_obj.insert("length", QJsonValue::fromVariant(movie.getLength()));
    movie_obj.insert("production_comp", QJsonValue::fromVariant(movie.getProd().c_str()));
    array.append(movie_obj);
}

void JsonVisitor::visit(Videogames& videogame) {
    QJsonObject videogame_obj;
    videogame_obj.insert("title", QJsonValue::fromVariant(videogame.getTitle().c_str()));
    videogame_obj.insert("tipo", QJsonValue::fromVariant("Videogame"));
    videogame_obj.insert("year", QJsonValue::fromVariant(videogame.getYear()));
    videogame_obj.insert("description", QJsonValue::fromVariant(videogame.getDescription().c_str()));
    videogame_obj.insert("genre", QJsonValue::fromVariant(videogame.getGenre().c_str()));
    videogame_obj.insert("country", QJsonValue::fromVariant(videogame.getCountry().c_str()));
    videogame_obj.insert("developer", QJsonValue::fromVariant(videogame.getDeveloper().c_str()));
    videogame_obj.insert("multiplayer", QJsonValue::fromVariant(QVariant(videogame.getMultiplayer()).toBool()));
    array.append(videogame_obj);
}
