#include "MovieForm.h"
#include "../../library/ItemController.h"
#include "../LengthEdit.h"
#include <QDialogButtonBox>
#include <QDebug>
#include <QPushButton>
MovieForm::MovieForm(QWidget* parent):NewItemForm(parent){
	setWindowTitle("Add new Movie");
	formLayout->addRow("Director: ", author);
	length = new LengthEdit("Minuti",this,1);
	formLayout->addRow("Length: ", length);
	movieScreenWriter = new QLineEdit(this);
	formLayout->addRow("Screenwriter: ", movieScreenWriter);
	movieProdComp = new QLineEdit(this);
	buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Production Company: ", movieProdComp);
	formLayout->addWidget(buttonBox);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	auto validate = [this](){enableButton();};
	connect(length, &QLineEdit::textChanged, this, validate);
	connect(movieScreenWriter, &QLineEdit::textChanged, this, validate);
	connect(movieProdComp, &QLineEdit::textChanged, this, validate);
}

void MovieForm::onAccepted(){
	accept();
	std::string _title = title->text().toStdString();
	unsigned int _year = year->text().toUInt();
	std::string _description = description->text().toStdString();
	std::string _genre = genre->text().toStdString();
	std::string _country = country->text().toStdString();
	std::string _image = image->text().toStdString();
	std::string _director = author->text().toStdString(); // "author" rappresenta il regista
	unsigned int _length = dynamic_cast<LengthEdit*>(length)->value(); // Durata del film
	std::string _screenwriter = movieScreenWriter->text().toStdString();
	std::string _productionCompany = movieProdComp->text().toStdString();

	qDebug() << "Title:" << QString::fromStdString(_title);
	qDebug() << "Year:" << _year;
	qDebug() << "Description:" << QString::fromStdString(_description);
	qDebug() << "Genre:" << QString::fromStdString(_genre);
	qDebug() << "Country:" << QString::fromStdString(_country);
	qDebug() << "Image path:" << QString::fromStdString(_image);
	qDebug() << "Director:" << QString::fromStdString(_director);
	qDebug() << "Length:" << _length;
	qDebug() << "Screenwriter:" << QString::fromStdString(_screenwriter);
	qDebug() << "Production company:" << QString::fromStdString(_productionCompany);
	ItemController::passMovie(_title, _year, _description, _genre, _country, _image, _director, _screenwriter, _length, _productionCompany);
}

bool MovieForm::validateInputs() const{
	bool primaryFields=NewItemForm::validateInputs();
	bool validFields=!movieProdComp->text().isEmpty()&&!movieScreenWriter->text().isEmpty()&&!length->text().isEmpty();
	return primaryFields&&validFields;
}

void MovieForm::enableButton(){
	if (validateInputs()){
		buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
	}
}


