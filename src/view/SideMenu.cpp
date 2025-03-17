#include "SideMenu.h"
#include "LibraryListModel.h"
SideMenu::SideMenu(LibraryModelFilter* filterProxy, QWidget* parent):QWidget(parent), filterProxy(filterProxy){
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
	connect(all, &QPushButton::clicked, this, [this, filterProxy]() {filterProxy->setFilterEnabled(false); });
	connect(album, &QPushButton::clicked, this, [this, filterProxy]() {filterProxy->setFilterCategory("Album"); });
	connect(book, &QPushButton::clicked, this, [this, filterProxy]() {filterProxy->setFilterCategory("Book"); });
	connect(comic, &QPushButton::clicked, this, [this, filterProxy]() {filterProxy->setFilterCategory("Comic"); });
	connect(movie, &QPushButton::clicked, this, [this, filterProxy]() {filterProxy->setFilterCategory("Movie"); });
	connect(videogame, &QPushButton::clicked, this, [this, filterProxy]() {filterProxy->setFilterCategory("Videogame"); });
}
