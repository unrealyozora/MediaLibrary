#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H
#include <qjsonarray.h>
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/movie.h"
#include "../items/Videogames.h"
#include "../items/ItemVisitor.h"

class JsonVisitor: public ItemVisitor{
private:
    QJsonArray array;
public:
    QJsonArray getArray() const;
    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;
};
#endif
