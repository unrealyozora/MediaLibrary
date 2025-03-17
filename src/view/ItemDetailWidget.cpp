#include "ItemDetailWidget.h"
#include <QVBoxLayout>
ItemWidget::ItemWidget(QWidget* parent):QWidget(parent) {
	QVBoxLayout* layout = new QVBoxLayout(this);
	backButton = new QPushButton("Back");
	label = new QLabel("Dettagli prova");
	layout->addWidget(backButton);
	layout->addWidget(label);
	setLayout(layout);
	connect(backButton, &QPushButton::clicked, this, &ItemWidget::backToHome);
}

void ItemWidget::showDetails(AbstractItem* item){
	if (item) {
		qDebug("showDetails entrato");//debug only
		label->setText(item->getDescription().c_str());
	}
}
