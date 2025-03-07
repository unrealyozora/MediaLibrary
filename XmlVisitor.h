#ifndef XML_VISITOR_H
#define XML_VISITOR_H
#include <ItemVisitor.h>
class XmlVisitor : public ItemVisitor {
private:

public:
    virtual void visit(Album& album);
    virtual void visit(Books& book);
    virtual void visit(Comic& comic);
    virtual void visit(Movie& movie);
    virtual void visit(Videogames& videogame);
};
#endif
