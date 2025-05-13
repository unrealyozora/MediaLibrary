#include "AlbumForm.h"
#include "../../library/ItemController.h"
#include <QDialogButtonBox>
#include <QDebug>
#include <QPushButton>
AlbumForm::AlbumForm(QWidget* parent):NewItemForm(parent){
	formLayout->addRow("Author: ", author);
	formLayout->addRow("Length: ", length);
	albumsongs = new QLineEdit(this);
	formLayout->addRow("Songs: ", albumsongs);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addWidget(buttonBox);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	auto validate = [this](){validateInputs();};
	connect(albumsongs, &QLineEdit::textChanged, this, validate);
}

void AlbumForm::onAccepted(){
	accept();
	std::string _title = title->text().toStdString();
	unsigned int _year = year->text().toUInt();
	std::string _description = description->text().toStdString();
	std::string _genre = genre->text().toStdString();
	std::string _country = country->text().toStdString();
	std::string _image = image->text().toStdString();
	std::string _author = author->text().toStdString();
	unsigned int _songs = albumsongs->text().toUInt();
	unsigned int _length = length->text().toUInt();

	qDebug()<<albumsongs->text();
	ItemController::passAlbum(_title, _year, _description, _genre, _country, _image, _author, _songs, _length);
}

bool AlbumForm::validateInputs(){
	qDebug()<<"album validating";
	bool primaryFields=NewItemForm::validateInputs();
	bool validFields=!albumsongs->text().isEmpty();
	if (primaryFields && validFields){
		buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
		return true;
	}
	return false;
}
