#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H
#include <qjsonarray.h>
#include <album.h>
#include <Books.h>
#include <Comic.h>
#include <movie.h>
#include <Videogames.h>
#include <ItemVisitor.h>

class JsonVisitor: public ItemVisitor{
private:
    QJsonArray array;
public:
    QJsonArray getArray() const;
    virtual void visit(Album& album);
    virtual void visit(Books& book);
    virtual void visit(Comic& comic);
    virtual void visit(Movie& movie);
    virtual void visit(Videogames& videogame);
};
#endif