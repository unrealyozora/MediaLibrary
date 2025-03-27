#include "AlbumForm.h"
#include "../../library/ItemController.h"
#include <QFormLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QDialogButtonBox>
AlbumForm::AlbumForm(QWidget* parent):NewItemForm(parent){
	setWindowTitle("Add new item");
	title = new QLineEdit();
	year = new QLineEdit();
	description = new QLineEdit();
	genre = new QLineEdit();
	country = new QLineEdit();
	//imageWidget= new QWidget(this);
	imageLayout = new QHBoxLayout();
	QPushButton* imageButton = new QPushButton("Browse", this);
	image = new QLineEdit();
	imageLayout->addWidget(image, Qt::AlignLeft);
	imageLayout->addWidget(imageButton);
	//imageWidget->setLayout(imageLayout);
	author = new QLineEdit();
	length = new QLineEdit();
	connect(imageButton, &QPushButton::clicked, this, [this]() {
		QString path = QFileDialog::getOpenFileName(this, "Select a file", "", "Library File (*.jpg *.png);;Tutti i file (*.*)");
		image->setText(path);
		});
	QFormLayout* formLayout = new QFormLayout(this);
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:", imageLayout);
	formLayout->addRow("Author: ", author);
	formLayout->addRow("Length: ", length);
	albumsongs = new QLineEdit(this);
	formLayout->addRow("Songs: ", albumsongs);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addWidget(buttonBox);
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
	ItemController::passAlbum(_title, _year, _description, _genre, _country, _image, _author, _songs, _length);
}
