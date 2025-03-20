#include "ItemDetailWidget.h"
#include "ItemDetailVisitor.h"
#include <QVBoxLayout>

ItemDetailsWidget::ItemDetailsWidget(QWidget* parent):QWidget(parent) {
	
}

void ItemDetailsWidget::showDetails(AbstractItem* item){
	if (item) {
		qDebug("showDetails entrato");//debug only
		ItemDetailVisitor visitor(this);
		item->accept(visitor);
		//label->setText(item->getDescription().c_str());
	}
}