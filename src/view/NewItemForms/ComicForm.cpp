#include "ComicForm.h"
#include "../../library/ItemController.h"
#include "../LengthEdit.h"
#include <QDialogButtonBox>
#include <QPushButton>
ComicForm::ComicForm(QWidget* parent):NewItemForm(parent){
	setWindowTitle("Add new Comic");
	formLayout->addRow("Author: ", author);
	length = new LengthEdit("Chapters",this,1);
	buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Chapters: ", length);
	formLayout->addWidget(buttonBox);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	auto validate = [this](){enableButton();};
	connect(length, &QLineEdit::textChanged, this, validate);
}

void ComicForm::onAccepted(){
	accept();
	std::string _title = title->text().toStdString();
	unsigned int _year = year->text().toUInt();
	std::string _description = description->text().toStdString();
	std::string _genre = genre->text().toStdString();
	std::string _country = country->text().toStdString();
	std::string _image = image->text().toStdString();
	std::string _author = author->text().toStdString();
	unsigned int _chapters = dynamic_cast<LengthEdit*>(length)->value(); // length è una LengthEdit, eredita sicuramente da QLineEdit per definizione
	qDebug() << _chapters;
	ItemController::passComic(_title, _year, _description, _genre, _country, _image, _author, _chapters);
}

bool ComicForm::validateInputs() const{
	bool primaryFields=NewItemForm::validateInputs();
	bool validFields=!length->text().isEmpty();
	return primaryFields&&validFields;
}

void ComicForm::enableButton(){
	if (validateInputs()){
		buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	}
}

