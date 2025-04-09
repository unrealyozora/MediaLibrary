#ifndef ITEMDETAILVISITOR_H
#define ITEMDETAILVISITOR_H
#include <QLineEdit>
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
    ItemDetailsWidget* widget;
    const unsigned int spacing = 20;
public:
    explicit ItemDetailVisitor(ItemDetailsWidget* _widget) : widget(_widget) {}

    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;

    void setLineEditFlat(const QList<QLineEdit*>* editList);
    void saveChanges(AbstractItem& item, QList<QLineEdit*>* editList);
    void setYearValidator(QLineEdit* yearEdit);
public slots:
    void setLineEditWrite(const QList<QLineEdit*>* editList);
    void deleteItem(const QString& title, const unsigned int year);
};

#endif