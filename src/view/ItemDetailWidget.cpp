#include "ItemDetailWidget.h"
#include "ItemDetailVisitor.h"
#include <QVBoxLayout>

ItemWidget::ItemWidget(QWidget* parent):QWidget(parent) {
	/*QVBoxLayout* layout = new QVBoxLayout(this);
	label = new QLabel("Item Details", this);
	backButton = new QPushButton("Back", this);
=======
ItemDetailWidget::ItemDetailWidget(QWidget* parent):QWidget(parent) {
	QVBoxLayout* layout = new QVBoxLayout(this);
	backButton = new QPushButton("Back");
	label = new QLabel("Dettagli prova");
	layout->addWidget(backButton);
>>>>>>> 0bf1f876e9248fdbf3a88ba74e4fc2609221490e
	layout->addWidget(label);
	layout->addWidget(backButton);
	setLayout(layout);
<<<<<<< HEAD
	connect(backButton, &QPushButton::clicked, this, &ItemWidget::backToHome);*/

	//connect(backButton, &QPushButton::clicked, this, &ItemDetailWidget::backToHome);

}

void ItemWidget::showDetails(AbstractItem* item){
	if (item) {
		qDebug("showDetails entrato");//debug only
		ItemDetailVisitor visitor(this);
		item->accept(visitor);
		//label->setText(item->getDescription().c_str());
	}
}