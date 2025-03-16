#include "SideMenu.h"

SideMenu::SideMenu(QWidget* parent):QWidget(parent){
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
	/*-------------------------------------------------------------------*/
	connect(album, &QPushButton::clicked, this, [this]() { emit categoryChanged("Album"); });
	connect(book, &QPushButton::clicked, this, [this]() { emit categoryChanged("Book"); });
	connect(comic, &QPushButton::clicked, this, [this]() { emit categoryChanged("Comic"); });
	connect(movie, &QPushButton::clicked, this, [this]() { emit categoryChanged("Movie"); });
	connect(videogame, &QPushButton::clicked, this, [this]() { emit categoryChanged("Videogame"); });

	/*-------------------------------------------------------------------*/
}
