#include "ItemDetailWidget.h"
#include "ItemDetailVisitor.h"
#include <QVBoxLayout>

ItemDetailsWidget::ItemDetailsWidget(QWidget* parent):QWidget(parent) {
	//setLayout(layout);
}

void ItemDetailsWidget::showDetails(AbstractItem* item){
    
        
	if (item) {
        while (QWidget* w = findChild<QWidget*>()) {
            delete w;
        }
		qDebug("showDetails entrato");//debug only
		ItemDetailVisitor visitor(this);
		item->accept(visitor);
	}
}


//QVBoxLayout* ItemDetailsWidget::getLayout(){
//	return layout;
//}
