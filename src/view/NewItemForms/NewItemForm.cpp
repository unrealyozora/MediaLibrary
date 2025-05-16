#include "NewItemForm.h"
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QIntValidator>
NewItemForm::NewItemForm(QWidget* parent):QDialog(parent){
	formLayout = new QFormLayout(this);
    setWindowTitle("Add new item");
	title = new QLineEdit();
	year = new QLineEdit();
	setYearValidator(year);
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
	auto validate = [this](){enableButton();};
	connect(title, &QLineEdit::textChanged, this, validate);
	connect(year, &QLineEdit::textChanged, this, validate);
	connect(description, &QLineEdit::textChanged, this, validate);
	connect(genre, &QLineEdit::textChanged, this, validate);
	connect(country, &QLineEdit::textChanged, this, validate);
	connect(image, &QLineEdit::textChanged, this, validate);
	connect(author, &QLineEdit::textChanged, this, validate);
}

bool NewItemForm::validateInputs() const{
	bool validFields=!title->text().isEmpty() &&
	!year->text().isEmpty() &&
	!description->text().isEmpty() &&
	!genre->text().isEmpty() &&
	!country->text().isEmpty() &&
	!author->text().isEmpty();
	qDebug()<<validFields;
	return validFields;
}

void NewItemForm::enableButton(){
	qDebug()<<"1button enabled";
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void NewItemForm::setYearValidator(QLineEdit* yearEdit){
	yearEdit->setValidator(new QIntValidator(0, 2100));
}


