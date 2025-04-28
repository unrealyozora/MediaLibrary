#include "ItemDetailWidget.h"
#include "ItemDetailVisitor.h"
#include <QVBoxLayout>
#include <QDebug>
ItemDetailsWidget::ItemDetailsWidget(QWidget* parent):QWidget(parent) {
	//setLayout(layout);
}

void ItemDetailsWidget::showDetails(AbstractItem* item){
    
        
	if (item) {
        while (QWidget* w = findChild<QWidget*>()) {
            delete w;
        }
		
		if (visitor!=nullptr){
			qDebug()<<"visitor delete";
			delete visitor;
		}
		qDebug("showDetails entrato");//debug only
		visitor = new ItemDetailVisitor(this);
		item->accept(*visitor);
	}
}



//QVBoxLayout* ItemDetailsWidget::getLayout(){
//	return layout;
//}
