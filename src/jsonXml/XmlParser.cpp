#include "XmlParser.h"
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/movie.h"
#include "../items/Videogames.h"

std::shared_ptr<AbstractItem> XmlParser::parseAlbum(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, image, author;
    unsigned int year = 0, songs = 0, length = 0, viewCount = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == QStringLiteral("item"))) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == QStringLiteral("title")) title = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("year")) year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("description")) description = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("genre")) genre = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("country")) country = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("image")) image = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("author")) author = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("songs")) songs = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("length")) length = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("view_count")) viewCount = xmlReader.readElementText().toUInt();
        }
    }

    auto item = std::make_shared<Album>(title.toStdString(), year, description.toStdString(), genre.toStdString(),
        country.toStdString(), image.toStdString(), author.toStdString(), songs, length);
    item->setViewCount(viewCount);
    return item;
}

std::shared_ptr<AbstractItem> XmlParser::parseBook(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, image, author, publ_house;
    unsigned int year = 0, pages = 0, viewCount = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == QStringLiteral("item"))) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == QStringLiteral("title")) title = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("year")) year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("description")) description = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("genre")) genre = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("country")) country = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("image")) image = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("author")) author = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("pages")) pages = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("publ")) publ_house = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("view_count")) viewCount = xmlReader.readElementText().toUInt();
        }
    }

    auto item = std::make_shared<Books>(title.toStdString(), year, description.toStdString(), genre.toStdString(),
        country.toStdString(), image.toStdString(), author.toStdString(), pages, publ_house.toStdString());
    item->setViewCount(viewCount);
    return item;
}

std::shared_ptr<AbstractItem> XmlParser::parseComic(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, image, author;
    unsigned int year = 0, chapters = 0, viewCount = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == QStringLiteral("item"))) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == QStringLiteral("title")) title = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("year")) year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("description")) description = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("genre")) genre = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("country")) country = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("image")) image = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("author")) author = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("chapters")) chapters = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("view_count")) viewCount = xmlReader.readElementText().toUInt();
        }
    }

    auto item = std::make_shared<Comic>(title.toStdString(), year, description.toStdString(), genre.toStdString(),
        country.toStdString(), image.toStdString(), author.toStdString(), chapters);
    item->setViewCount(viewCount);
    return item;
}

std::shared_ptr<AbstractItem> XmlParser::parseMovie(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, image, director, screenwriter, production_company;
    unsigned int year = 0, length = 0, viewCount = 0;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == QStringLiteral("item"))) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == QStringLiteral("title")) title = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("year")) year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("description")) description = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("genre")) genre = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("country")) country = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("image")) image = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("director")) director = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("screenwriter")) screenwriter = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("length")) length = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("production_comp")) production_company = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("view_count")) viewCount = xmlReader.readElementText().toUInt();
        }
    }

    auto item = std::make_shared<Movie>(title.toStdString(), year, description.toStdString(), genre.toStdString(),
        country.toStdString(), image.toStdString(), director.toStdString(),
        screenwriter.toStdString(), length, production_company.toStdString());
    item->setViewCount(viewCount);
    return item;
}

std::shared_ptr<AbstractItem> XmlParser::parseVideogame(QXmlStreamReader& xmlReader) {
    QString title, description, genre, country, image, developer;
    unsigned int year = 0, viewCount = 0;
    bool multiplayer = false;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == QStringLiteral("item"))) {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement) {
            if (xmlReader.name() == QStringLiteral("title")) title = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("year")) year = xmlReader.readElementText().toUInt();
            else if (xmlReader.name() == QStringLiteral("description")) description = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("genre")) genre = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("country")) country = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("image")) image = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("developer")) developer = xmlReader.readElementText();
            else if (xmlReader.name() == QStringLiteral("multiplayer"))
                multiplayer = (xmlReader.readElementText().toLower() == QStringLiteral("true"));
            else if (xmlReader.name() == QStringLiteral("view_count")) viewCount = xmlReader.readElementText().toUInt();
        }
    }

    auto item = std::make_shared<Videogames>(title.toStdString(), year, description.toStdString(), genre.toStdString(),
        country.toStdString(), image.toStdString(), developer.toStdString(), multiplayer);
    item->setViewCount(viewCount);
    return item;
}
