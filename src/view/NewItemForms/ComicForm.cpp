#include "ComicForm.h"
#include "../../library/ItemController.h"
#include <QDialogButtonBox>
ComicForm::ComicForm(QWidget* parent):NewItemForm(parent){
	length = new QLineEdit();
	QFormLayout* formLayout = new QFormLayout(this);
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:", imageLayout);
	formLayout->addRow("Author: ", author);
	length = new QLineEdit(this);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Chapters: ", length);
	formLayout->addWidget(buttonBox);
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
	unsigned int _chapters = length->text().toUInt(); // "length" qui rappresenta i capitoli (da cambiare forse)!
	ItemController::passComic(_title, _year, _description, _genre, _country, _image, _author, _chapters);
}

