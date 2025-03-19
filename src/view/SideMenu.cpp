#include "SideMenu.h"
#include "LibraryListModel.h"
SideMenu::SideMenu(LibraryCategoryFilter* categoryProxy, LibraryQueryFilter* queryProxy, QStackedWidget* stackedWidget, QWidget* parent):QWidget(parent), categoryProxy(categoryProxy), queryProxy(queryProxy), stackedWidget(stackedWidget){
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);
	all = new QPushButton("All");
	album = new QPushButton("Albums");
	book= new QPushButton("Books");
	comic = new QPushButton("Comics");
	movie = new QPushButton("Movies");
	videogame = new QPushButton("Videogames");
	all->setFlat(true);
	album->setFlat(true);
	book->setFlat(true);
	comic->setFlat(true);
	movie->setFlat(true);
	videogame->setFlat(true);
	all->setCheckable(true);
	all->setChecked(true);
	album->setCheckable(true);
	book->setCheckable(true);
	comic->setCheckable(true);
	movie->setCheckable(true);
	videogame->setCheckable(true);
	all->setAutoExclusive(true);
	album->setAutoExclusive(true);
	book->setAutoExclusive(true);
	comic->setAutoExclusive(true);
	movie->setAutoExclusive(true);
	videogame->setAutoExclusive(true);
	searchbar = new QLineEdit(this);
	searchbar->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
	searchbar->setPlaceholderText("Search...");
	layout->addWidget(searchbar);
	layout->addWidget(all);
	layout->addWidget(album);
	layout->addWidget(book);
	layout->addWidget(comic);
	layout->addWidget(movie);
	layout->addWidget(videogame);
	connect(all, &QPushButton::clicked, this, [this, categoryProxy, stackedWidget]() {categoryProxy->setFilterEnabled(false); stackedWidget->setCurrentIndex(0); });
	connect(album, &QPushButton::clicked, this, [this, categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Album"); stackedWidget->setCurrentIndex(0); });
	connect(book, &QPushButton::clicked, this, [this, categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Book"); stackedWidget->setCurrentIndex(0); });
	connect(comic, &QPushButton::clicked, this, [this, categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Comic"); stackedWidget->setCurrentIndex(0); });
	connect(movie, &QPushButton::clicked, this, [this, categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Movie"); stackedWidget->setCurrentIndex(0); });
	connect(videogame, &QPushButton::clicked, this, [this, categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Videogame"); stackedWidget->setCurrentIndex(0); });
    connect(searchbar, &QLineEdit::textChanged, queryProxy, &LibraryQueryFilter::setQuery);
}
