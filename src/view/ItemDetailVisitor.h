#ifndef ITEMDETAILVISITOR_H
#define ITEMDETAILVISITOR_H
#include <QLineEdit>
#include <QComboBox>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "../items/ItemVisitor.h"
#include "../view/ItemDetailWidget.h"
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/movie.h"
#include "../items/Videogames.h"

class ItemDetailVisitor : public ItemVisitor {
private:
    QHBoxLayout* mainLayout;
    QVBoxLayout* imageLayout;
    QVBoxLayout* infoLayout;
    QWidget* infoWidget;
    QHBoxLayout* titleLayout;
    QVBoxLayout* rightLayout;
    ItemDetailsWidget* widget;
    const unsigned int spacing = 20;
    QList<QLineEdit*>* editList=nullptr;
    QLabel* imageLabel;
    QPixmap pixmap;
    QLineEdit* yearEdit;
    QLabel* titleLabel;
    QPushButton* editTitleButton;
public:
    explicit ItemDetailVisitor(ItemDetailsWidget* _widget) : widget(_widget) {}

    void initialSetup(AbstractItem& item);
    void finalSetup(AbstractItem& item);
    void visit(Album& album) override;
    void visit(Books& book) override;
    void visit(Comic& comic) override;
    void visit(Movie& movie) override;
    void visit(Videogames& videogame) override;

    void setLineEditFlat(const QList<QLineEdit*>* editList) const;
    void saveChanges(AbstractItem& item,QLabel& title, QList<QLineEdit*>* editList, QComboBox* multiplayerEdit = nullptr) const;
    void setYearValidator(QLineEdit* yearEdit) const;
public slots:
    void setLineEditWrite(const QList<QLineEdit*>* editList) const;
    void deleteItem(const QString& title, const unsigned int year) const;
    void setNewImage(AbstractItem& item);
};

#endif