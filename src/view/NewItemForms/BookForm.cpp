#include "BookForm.h"
#include "../../library/ItemController.h"
#include "../LengthEdit.h"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QDebug>
BookForm::BookForm(QWidget* parent):NewItemForm(parent){
	setWindowTitle("Add new Book");
	formLayout->addRow("Author: ", author);
	length = new LengthEdit("Pages",this,1);
	formLayout->addRow("Pages: ", length);
	bookPublHouse = new QLineEdit(this);
	buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Publishing House: ", bookPublHouse);
	formLayout->addWidget(buttonBox);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	auto validate = [this](){enableButton();};
	connect(bookPublHouse, &QLineEdit::textChanged, this, validate);
	connect(length, &QLineEdit::textChanged, this, validate);
}

void BookForm::onAccepted(){
	accept();
	std::string _title = title->text().toStdString();
	unsigned int _year = year->text().toUInt();
	std::string _description = description->text().toStdString();
	std::string _genre = genre->text().toStdString();
	std::string _country = country->text().toStdString();
	std::string _image = image->text().toStdString();
	std::string _author = author->text().toStdString();
	std::string _publHouse = bookPublHouse->text().toStdString();
	unsigned int _pages = length->text().toUInt();
	ItemController::passBook(_title, _year, _description, _genre, _country, _image, _author, _pages, _publHouse);
}

bool BookForm::validateInputs() const{
	bool primaryFields=NewItemForm::validateInputs();
	bool validFields=!bookPublHouse->text().isEmpty()&&!length->text().isEmpty();
	return primaryFields&&validFields;
}

void BookForm::enableButton(){
	if (validateInputs()){
		buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	}
}


