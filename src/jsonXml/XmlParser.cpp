#include "XmlParser.h"
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/Movie.h"
#include "../items/Videogames.h"

#include <iostream>//debug only

std::shared_ptr<AbstractItem> XmlParser::parseAlbum(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, author;
    unsigned int year = 0, songs = 0, length = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "item")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "author") author = xmlReader.readElementText();
            else if (xmlReader.name() == "songs") songs = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "length") length = xmlReader.readElementText().toUInt();
        }
    }
    return std::make_shared<Album>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), author.toStdString(), songs, length);
}

std::shared_ptr<AbstractItem> XmlParser::parseBook(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, author, publ_house;
    unsigned int year = 0, pages = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "item")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "author") author = xmlReader.readElementText();
            else if (xmlReader.name() == "pages") pages = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "publ") publ_house = xmlReader.readElementText();
        }
    }
    return std::make_shared<Books>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), author.toStdString(), pages, publ_house.toStdString());
}

std::shared_ptr<AbstractItem> XmlParser::parseComic(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, author;
    unsigned int year = 0, chapters = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "item")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "author") author = xmlReader.readElementText();
            else if (xmlReader.name() == "chapters") chapters = xmlReader.readElementText().toUInt();
        }
    }
    return std::make_shared<Comic>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), author.toStdString(), chapters);
}

std::shared_ptr<AbstractItem> XmlParser::parseMovie(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, director, screenwriter, production_company;
    unsigned int year = 0, length = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name()=="item")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "director") director = xmlReader.readElementText();
            else if (xmlReader.name() == "screenwriter") screenwriter = xmlReader.readElementText();
            else if (xmlReader.name() == "length") length = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "production_comp") production_company = xmlReader.readElementText();
        }
    }
    return std::make_shared<Movie>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), director.toStdString(), screenwriter.toStdString(), length, production_company.toStdString());
}

std::shared_ptr<AbstractItem> XmlParser::parseVideogame(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, developer;
    unsigned int year = 0;
    bool multiplayer = false;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "item")) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == "title") title = xmlReader.readElementText();
            else if (xmlReader.name() == "year") year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == "description") description = xmlReader.readElementText();
            else if (xmlReader.name() == "genre") genre = xmlReader.readElementText();
            else if (xmlReader.name() == "country") country = xmlReader.readElementText();
            else if (xmlReader.name() == "developer") developer = xmlReader.readElementText();
            else if (xmlReader.name() == "multiplayer") multiplayer = (xmlReader.readElementText().toLower() == "true");
        }
    }
    return std::make_shared<Videogames>(title.toStdString(), year, description.toStdString(), genre.toStdString(), country.toStdString(), developer.toStdString(), multiplayer);
}
