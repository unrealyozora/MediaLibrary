#ifndef XML_VISITOR_H
#define XML_VISITOR_H

#include <QXmlStreamWriter>
#include "ItemVisitor.h"
#include "Album.h"
#include "Books.h"
#include "Comic.h"
#include "Movie.h"
#include "Videogames.h"

class XmlVisitor : public ItemVisitor {
private:
    QXmlStreamWriter& xmlWriter;

public:
    XmlVisitor(QXmlStreamWriter& writer);
    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;
};

#endif // XML_VISITOR_H

