#include "SaveEditsVisitor.h"
#include <QDebug>
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/movie.h"
#include "../items/Videogames.h"
#include "Library.h"
void SaveEditsVisitor::visit(Album& album){
	album.setYear(editList->at(0)->text().toUInt());
    album.setDescription(editList->at(1)->text().toStdString());
    album.setGenre(editList->at(2)->text().toStdString());
    album.setCountry(editList->at(3)->text().toStdString());
    album.setAuthor(editList->at(4)->text().toStdString());
    album.setSongs(editList->at(5)->text().toUInt());
    qDebug() << editList->at(6)->text();
    qDebug() << editList->at(6)->text().toUInt();
    QStringList lengthString = editList->at(6)->text().split(" ");
    album.setLength(lengthString[0].toUInt());

    Library::getInstance()->updateItem(album);
}

void SaveEditsVisitor::visit(Books& book){
    book.setYear(editList->at(0)->text().toUInt());
    book.setDescription(editList->at(1)->text().toStdString());
    book.setGenre(editList->at(2)->text().toStdString());
    book.setCountry(editList->at(3)->text().toStdString());
    book.setAuthor(editList->at(4)->text().toStdString());
    book.setPages(editList->at(5)->text().toUInt());
    book.setPub(editList->at(6)->text().toStdString());
}

void SaveEditsVisitor::visit(Comic& comic) {
    comic.setYear(editList->at(0)->text().toUInt());
    comic.setDescription(editList->at(1)->text().toStdString());
    comic.setGenre(editList->at(2)->text().toStdString());
    comic.setCountry(editList->at(3)->text().toStdString());
    comic.setAuthor(editList->at(4)->text().toStdString());
    comic.setChapters(editList->at(5)->text().toUInt());

    Library::getInstance()->updateItem(comic);
}

void SaveEditsVisitor::visit(Movie& movie) {
    movie.setYear(editList->at(0)->text().toUInt());
    movie.setDescription(editList->at(1)->text().toStdString());
    movie.setGenre(editList->at(2)->text().toStdString());
    movie.setCountry(editList->at(3)->text().toStdString());
    movie.setDirector(editList->at(4)->text().toStdString());
    movie.setScreenwriter(editList->at(5)->text().toStdString());
    QStringList lengthString = editList->at(6)->text().split(" ");
    movie.setLength(lengthString[0].toUInt());
    movie.setProd(editList->at(7)->text().toStdString());

    Library::getInstance()->updateItem(movie);
}

void SaveEditsVisitor::visit(Videogames& videogame) {
    videogame.setYear(editList->at(0)->text().toUInt());
    videogame.setDescription(editList->at(1)->text().toStdString());
    videogame.setGenre(editList->at(2)->text().toStdString());
    videogame.setCountry(editList->at(3)->text().toStdString());
    videogame.setDeveloper(editList->at(4)->text().toStdString());
    videogame.setMultiplayer(editList->at(5)->text() == "Yes");

    Library::getInstance()->updateItem(videogame);
}
