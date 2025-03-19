#ifndef ITEMDETAILVISITOR_H
#define ITEMDETAILVISITOR_H

#include "../items/ItemVisitor.h"
#include "../view/ItemDetailWidget.h"
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/movie.h"
#include "../items/Videogames.h"
#include "../items/ItemVisitor.h"

class ItemDetailVisitor : public ItemVisitor {
private:
    ItemDetailWidget* widget;

public:
    explicit ItemDetailVisitor(ItemDetailWidget* _widget) : widget(_widget) {}

    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;
};

#endif
