#include "VideogameForm.h"
#include "../../library/ItemController.h"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QPushButton>
VideogameForm::VideogameForm(QWidget* parent):NewItemForm(parent){
	formLayout->addRow("Developer: ", author);
	multiplayer = new QComboBox(this);
	multiplayer->addItem("Yes");
	multiplayer->addItem("No");
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Multiplayer: ", multiplayer);
	formLayout->addWidget(buttonBox);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void VideogameForm::onAccepted(){
	accept();
	std::string _title = title->text().toStdString();
	unsigned int _year = year->text().toUInt();
	std::string _description = description->text().toStdString();
	std::string _genre = genre->text().toStdString();
	std::string _country = country->text().toStdString();
	std::string _image = image->text().toStdString();
	std::string _developer = author->text().toStdString(); // "author" qui rappresenta lo sviluppatore
	bool _multiplayer = (multiplayer->currentText() == "Yes");
	ItemController::passVideogame(_title, _year, _description, _genre, _country, _image, _developer, _multiplayer);
}
