#include "ItemDetailWidget.h"
#include <QVBoxLayout>
ItemDetailWidget::ItemDetailWidget(QWidget* parent):QWidget(parent) {
	QVBoxLayout* layout = new QVBoxLayout(this);
	backButton = new QPushButton("Back");
	label = new QLabel("Dettagli prova");
	layout->addWidget(backButton);
	layout->addWidget(label);
	setLayout(layout);
	connect(backButton, &QPushButton::clicked, this, &ItemDetailWidget::backToHome);
}

void ItemDetailWidget::showDetails(AbstractItem* item){
	if (item) {
		qDebug("showDetails entrato");//debug only
		label->setText(item->getDescription().c_str());
	}
}
