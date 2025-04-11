#include "MovieForm.h"
#include "../../library/ItemController.h"
#include <QDialogButtonBox>
MovieForm::MovieForm(QWidget* parent):NewItemForm(parent){
	formLayout->addRow("Director: ", author);
	length = new QLineEdit(this);
	formLayout->addRow("Length: ", length);
	movieScreenWriter = new QLineEdit(this);
	formLayout->addRow("Screenwriter: ", movieScreenWriter);
	movieProdComp = new QLineEdit(this);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Production Company: ", movieProdComp);
	formLayout->addWidget(buttonBox);
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
	unsigned int _length = length->text().toUInt(); // Durata del film
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


