#ifndef VIEW_ITEM_DETAIL_H
#define VIEW_ITEM_DETAIL_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "../items/AbstractItem.h"
class ItemWidget :public QWidget {
	Q_OBJECT
private:
	QPushButton* backButton;
	QLabel* label;
public:
	explicit ItemWidget(QWidget* parent = nullptr);
	void showDetails(AbstractItem* item);
signals:
	void backToHome();
};
#endif
