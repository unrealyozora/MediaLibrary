#include "../../library/ItemController.h"
#include "NewItemForm.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QFormLayout>
#include <QFileDialog>

#include <iostream> //debug only
NewItemForm::NewItemForm(QWidget* parent) :QDialog(parent) {
	setWindowTitle("Add new item");
	title = new QLineEdit();
	year = new QLineEdit();
	description = new QLineEdit();
	genre = new QLineEdit();
	country = new QLineEdit();
	//imageWidget= new QWidget(this);
	imageLayout= new QHBoxLayout();
	QPushButton* imageButton = new QPushButton("Browse", this);
	image = new QLineEdit();
	imageLayout->addWidget(image, Qt::AlignLeft);
	imageLayout->addWidget(imageButton);
	//imageWidget->setLayout(imageLayout);
	author = new QLineEdit();
	length = new QLineEdit();
	connect(imageButton, &QPushButton::clicked,  this, [this](){
		QString path= QFileDialog::getOpenFileName(this, "Select a file", "", "Library File (*.jpg *.png);;Tutti i file (*.*)");
		image->setText(path);
	});
}

void NewItemForm::setupAlbumForm(){
	qDebug("newAlbumForm");
	QFormLayout* formLayout = new QFormLayout(this);
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:" ,imageLayout);
	formLayout->addRow("Author: ", author);
	formLayout->addRow("Length: ", length);
	albumsongs = new QLineEdit(this);
	formLayout->addRow("Songs: ", albumsongs);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel,this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addWidget(buttonBox);
}

void NewItemForm::setupBookForm(){
	QFormLayout* formLayout = new QFormLayout(this);
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:" ,imageLayout);
	formLayout->addRow("Author: ", author);
	length = new QLineEdit(this);
	formLayout->addRow("Pages: ", length);
	bookPublHouse = new QLineEdit(this);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Publishing House: ", bookPublHouse);
	formLayout->addWidget(buttonBox);
}

void NewItemForm::setupComicForm(){
	QFormLayout* formLayout = new QFormLayout(this);
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:" ,imageLayout);
	formLayout->addRow("Author: ", author);
	length = new QLineEdit(this);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Chapters: ", length);
	formLayout->addWidget(buttonBox);
}

void NewItemForm::setupMovieForm(){
	QFormLayout* formLayout = new QFormLayout(this);
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:" ,imageLayout);
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

void NewItemForm::setupVideogameForm(){
	QFormLayout* formLayout = new QFormLayout(this);
	formLayout->addRow("Title: ", title);
	formLayout->addRow("Year: ", year);
	formLayout->addRow("Description: ", description);
	formLayout->addRow("Genre: ", genre);
	formLayout->addRow("Country: ", country);
	formLayout->addRow("Image:" ,imageLayout);
	formLayout->addRow("Developer: ", author);
	multiplayer = new QLineEdit(this);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &NewItemForm::onAccepted);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	formLayout->addRow("Multiplayer: ", multiplayer);
	formLayout->addWidget(buttonBox);
}

void NewItemForm::initializeAlbumForm(){
	NewItemForm AlbumForm;
	//NewItemForm* AlbumForm = new NewItemForm();
	AlbumForm.setupAlbumForm();
	AlbumForm.exec();
}

void NewItemForm::initializeBookForm(){
	NewItemForm BookForm;
	BookForm.setupBookForm();
	BookForm.exec();
}

void NewItemForm::initializeComicForm(){
	NewItemForm ComicForm;
	ComicForm.setupComicForm();
	ComicForm.exec();
}

void NewItemForm::initializeMovieForm(){
	NewItemForm MovieForm;
	MovieForm.setupMovieForm();
	MovieForm.exec();
}

void NewItemForm::initializeVideogameForm(){
	NewItemForm VideogameForm;
	VideogameForm.setupAlbumForm();
	VideogameForm.exec();
}

void NewItemForm::onAccepted() {
	accept();
	ItemController::createMockAlbum();
	for (auto x : Library::getInstance()->getList()) {
		std::cout << "item created: " << x->getTitle();
	}
	
}
