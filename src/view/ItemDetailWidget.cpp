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
		
		if (visitor!=nullptr){
			delete visitor;
		}
		visitor = new ItemDetailVisitor(this);
		item->accept(*visitor);
	}
}
