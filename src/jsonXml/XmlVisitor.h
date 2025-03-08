#ifndef XML_VISITOR_H
#define XML_VISITOR_H

#include <QXmlStreamWriter>
#include "../items/ItemVisitor.h"
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/Movie.h"
#include "../items/Videogames.h"

class XmlVisitor : public ItemVisitor {
private:
    QXmlStreamWriter& xmlWriter;

public:
    explicit XmlVisitor(QXmlStreamWriter& writer);
    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;
};

#endif // XML_VISITOR_H

