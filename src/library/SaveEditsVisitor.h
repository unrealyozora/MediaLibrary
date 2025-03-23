#ifndef LIBRARY_SAVE_EDITS_VISITOR_H
#define LIBRARY_SAVE_EDITS_VISITOR_H
#include "../items/ItemVisitor.h"
#include <QList>
#include <QLineEdit>
class SaveEditsVisitor : public ItemVisitor {
private:
    QList<QLineEdit*>*& editList;
public:
    explicit SaveEditsVisitor(QList<QLineEdit*>*& _editList) :editList(_editList) {};
    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;
};
#endif