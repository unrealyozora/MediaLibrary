#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <memory>
#include <QXmlStreamReader>
#include "../items/AbstractItem.h"

class XmlParser {
public:
    static std::shared_ptr<AbstractItem> parseAlbum(QXmlStreamReader& xmlReader);
    static std::shared_ptr<AbstractItem> parseBook(QXmlStreamReader& xmlReader);
    static std::shared_ptr<AbstractItem> parseComic(QXmlStreamReader& xmlReader);
    static std::shared_ptr<AbstractItem> parseMovie(QXmlStreamReader& xmlReader);
    static std::shared_ptr<AbstractItem> parseVideogame(QXmlStreamReader& xmlReader);
};

#endif // XMLPARSER_H
