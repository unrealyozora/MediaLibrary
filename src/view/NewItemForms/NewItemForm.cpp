#include "NewItemForm.h"
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
NewItemForm::NewItemForm(QWidget* parent):QDialog(parent){
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
	buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(imageButton, &QPushButton::clicked, this, [this]() {
		QString path = QFileDialog::getOpenFileName(this, "Select a file", "", "Library File (*.jpg *.png)");
		image->setText(path);
		});
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:", imageLayout);

	auto validate = [this](){validateInputs();};
	connect(title, &QLineEdit::textChanged, this, validate);
	connect(year, &QLineEdit::textChanged, this, validate);
	connect(description, &QLineEdit::textChanged, this, validate);
	connect(genre, &QLineEdit::textChanged, this, validate);
	connect(country, &QLineEdit::textChanged, this, validate);
	connect(image, &QLineEdit::textChanged, this, validate);
	connect(author, &QLineEdit::textChanged, this, validate);
	connect(length, &QLineEdit::textChanged, this, validate);
}

bool NewItemForm::validateInputs(){
	bool validFields=!title->text().isEmpty() &&
	!year->text().isEmpty() &&
	!description->text().isEmpty() &&
	!genre->text().isEmpty() &&
	!country->text().isEmpty() &&
	!author->text().isEmpty() && 
	!length->text().isEmpty();
	return validFields;
}
