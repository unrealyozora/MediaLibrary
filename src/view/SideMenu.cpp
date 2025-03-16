#include "SideMenu.h"
#include "LibraryListModel.h"
SideMenu::SideMenu(LibraryModelFilter* filterProxy, QWidget* parent):QWidget(parent), filterProxy(filterProxy){
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);
	album = new QPushButton("Albums");
	book= new QPushButton("Books");
	comic = new QPushButton("Comics");
	movie = new QPushButton("Movies");
	videogame = new QPushButton("Videogames");
	layout->addWidget(album);
	layout->addWidget(book);
	layout->addWidget(comic);
	layout->addWidget(movie);
	layout->addWidget(videogame);
	connect(album, &QPushButton::clicked, this, [this, filterProxy]() {filterProxy->setFilterCategory("Album"); });
}
