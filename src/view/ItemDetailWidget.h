#ifndef VIEW_ITEM_DETAIL_H
#define VIEW_ITEM_DETAIL_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "../items/AbstractItem.h"
class ItemDetailVisitor;
class ItemDetailsWidget :public QWidget {
	Q_OBJECT
private:
	ItemDetailVisitor* visitor;
public:
	explicit ItemDetailsWidget(QWidget* parent = nullptr);
	void showDetails(AbstractItem* item);
	//QVBoxLayout* getLayout();
signals:
	void backToHome();
	//void modifyItem();

};
#endif
