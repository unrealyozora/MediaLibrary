#include "XmlParser.h"
#include "Album.h"
#include "Books.h"
#include "Comic.h"
#include "Movie.h"
#include "Videogames.h"

std::shared_ptr<AbstractItem> XmlParser::parseAlbum(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, author;
    unsigned int year = 0, songs = 0, length = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "Album")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "Title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "Year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "Description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "Genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "Country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "Author") author = xmlReader.readElementText();
            else if (xmlReader.name() == "Songs") songs = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "Length") length = xmlReader.readElementText().toUInt();
        }
    }
    return std::make_shared<Album>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), author.toStdString(), songs, length);
}

std::shared_ptr<AbstractItem> XmlParser::parseBook(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, author, publ_house;
    unsigned int year = 0, pages = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "Book")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "Title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "Year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "Description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "Genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "Country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "Author") author = xmlReader.readElementText();
            else if (xmlReader.name() == "Pages") pages = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "Publisher") publ_house = xmlReader.readElementText();
        }
    }
    return std::make_shared<Books>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), author.toStdString(), pages, publ_house.toStdString());
}

std::shared_ptr<AbstractItem> XmlParser::parseComic(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, author;
    unsigned int year = 0, chapters = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "Comic")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "Title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "Year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "Description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "Genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "Country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "Author") author = xmlReader.readElementText();
            else if (xmlReader.name() == "Chapters") chapters = xmlReader.readElementText().toUInt();
        }
    }
    return std::make_shared<Comic>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), author.toStdString(), chapters);
}

std::shared_ptr<AbstractItem> XmlParser::parseMovie(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, director, screenwriter, production_company;
    unsigned int year = 0, length = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "Movie")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "Title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "Year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "Description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "Genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "Country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "Director") director = xmlReader.readElementText();
            else if (xmlReader.name() == "Screenwriter") screenwriter = xmlReader.readElementText();
            else if (xmlReader.name() == "Length") length = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "ProductionCompany") production_company = xmlReader.readElementText();
        }
    }
    return std::make_shared<Movie>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), director.toStdString(), screenwriter.toStdString(), length, production_company.toStdString());
}

std::shared_ptr<AbstractItem> XmlParser::parseVideogame(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, developer;
    unsigned int year = 0;
    bool multiplayer = false;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "Videogame")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "Title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "Year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "Description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "Genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "Country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "Developer") developer = xmlReader.readElementText();
            else if (xmlReader.name() == "Multiplayer") multiplayer = (xmlReader.readElementText().toLower() == "true");
        }
    }
    return std::make_shared<Videogames>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), developer.toStdString(), multiplayer);
}
