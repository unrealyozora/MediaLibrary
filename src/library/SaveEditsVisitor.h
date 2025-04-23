#ifndef LIBRARY_SAVE_EDITS_VISITOR_H
#define LIBRARY_SAVE_EDITS_VISITOR_H
#include "../items/ItemVisitor.h"
#include <QList>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
class SaveEditsVisitor : public ItemVisitor {
private:
    QLabel& title;
    QList<QLineEdit*>*& editList;
    QComboBox*& multiplayerEdit;
public:
    explicit SaveEditsVisitor(QLabel& _title, QList<QLineEdit*>*& _editList, QComboBox*& _multiplayerEdit) :title(_title),editList(_editList), multiplayerEdit(_multiplayerEdit) {};
    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;
};
#endif