#include "ItemDetailWidget.h"
#include "ItemDetailVisitor.h"
#include <QVBoxLayout>
ItemWidget::ItemWidget(QWidget* parent):QWidget(parent) {
	/*QVBoxLayout* layout = new QVBoxLayout(this);
	label = new QLabel("Item Details", this);
	backButton = new QPushButton("Back", this);
	layout->addWidget(label);
	layout->addWidget(backButton);
	setLayout(layout);
	connect(backButton, &QPushButton::clicked, this, &ItemWidget::backToHome);*/
}

void ItemWidget::showDetails(AbstractItem* item){
	if (item) {
		qDebug("showDetails entrato");//debug only
		ItemDetailVisitor visitor(this);
		item->accept(visitor);
		//label->setText(item->getDescription().c_str());
	}
}