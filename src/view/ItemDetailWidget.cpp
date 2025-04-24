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
		qDebug("showDetails entrato");//debug only
		if (visitor!=nullptr){
			qDebug()<<"visitor delete";
			delete visitor;
		}
		visitor = new ItemDetailVisitor(this); 
		qDebug() << "this dopo creazione:" << &visitor;
		item->accept(*visitor);
	}
}



//QVBoxLayout* ItemDetailsWidget::getLayout(){
//	return layout;
//}
