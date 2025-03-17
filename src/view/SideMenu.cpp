#include "SideMenu.h"
#include "LibraryListModel.h"
SideMenu::SideMenu(LibraryModelFilter* filterProxy, QStackedWidget* stackedWidget, QWidget* parent):QWidget(parent), filterProxy(filterProxy), stackedWidget(stackedWidget){
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);
	all = new QPushButton("All");
	album = new QPushButton("Albums");
	book= new QPushButton("Books");
	comic = new QPushButton("Comics");
	movie = new QPushButton("Movies");
	videogame = new QPushButton("Videogames");
	layout->addWidget(all);
	layout->addWidget(album);
	layout->addWidget(book);
	layout->addWidget(comic);
	layout->addWidget(movie);
	layout->addWidget(videogame);
	connect(all, &QPushButton::clicked, this, [this, filterProxy, stackedWidget]() {filterProxy->setFilterEnabled(false); stackedWidget->setCurrentIndex(0); });
	connect(album, &QPushButton::clicked, this, [this, filterProxy, stackedWidget]() {filterProxy->setFilterCategory("Album"); stackedWidget->setCurrentIndex(0); });
	connect(book, &QPushButton::clicked, this, [this, filterProxy, stackedWidget]() {filterProxy->setFilterCategory("Book"); stackedWidget->setCurrentIndex(0); });
	connect(comic, &QPushButton::clicked, this, [this, filterProxy, stackedWidget]() {filterProxy->setFilterCategory("Comic"); stackedWidget->setCurrentIndex(0); });
	connect(movie, &QPushButton::clicked, this, [this, filterProxy, stackedWidget]() {filterProxy->setFilterCategory("Movie"); stackedWidget->setCurrentIndex(0); });
	connect(videogame, &QPushButton::clicked, this, [this, filterProxy, stackedWidget]() {filterProxy->setFilterCategory("Videogame"); stackedWidget->setCurrentIndex(0); });
}
