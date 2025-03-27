#include "MovieForm.h"
#include "../../library/ItemController.h"
#include <QFormLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QDialogButtonBox>
MovieForm::MovieForm(QWidget* parent):NewItemForm(parent){
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
	ItemController::passMovie(_title, _year, _description, _genre, _country, _image, _director, _screenwriter, _length, _productionCompany);
}


