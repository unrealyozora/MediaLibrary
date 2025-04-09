#include "SideMenu.h"
#include "LibraryListModel.h"
SideMenu::SideMenu(LibraryCategoryFilter* categoryProxy, LibraryQueryFilter* queryProxy, QStackedWidget* stackedWidget, QWidget* parent):QWidget(parent), categoryProxy(categoryProxy), queryProxy(queryProxy), stackedWidget(stackedWidget){
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setAlignment(Qt::AlignCenter | Qt::AlignTop);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	searchbar = new QLineEdit(this);
	searchbar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	searchbar->setFixedHeight(30);
	searchbar->setPlaceholderText("Search...");
	layout->addWidget(searchbar);
	QList<QPushButton*> buttonList;
	all = new QPushButton(QIcon(":icons/all"),"All");
	album = new QPushButton(QIcon(":icons/album"), "Albums");
	book= new QPushButton(QIcon(":icons/book"), "Books");
	comic = new QPushButton(QIcon(":icons/comic"),"Comics");
	movie = new QPushButton(QIcon(":icons/movie"),"Movies");
	videogame = new QPushButton(QIcon(":icons/videogame"),"Videogames");
	buttonList.append(all);
	buttonList.append(album);
	buttonList.append(book);
	buttonList.append(comic);
	buttonList.append(movie);
	buttonList.append(videogame);
	for (QPushButton* button : buttonList) {
		button->setFlat(true);
		button->setCheckable(true);
		button->setAutoExclusive(true);
		button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		button->setStyleSheet("text-align: left; padding-left: 10px;");
		button->setFixedHeight(30);
		layout->addWidget(button);
	}
	all->setChecked(true);
	connect(all, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterEnabled(false); stackedWidget->setCurrentIndex(0); });
	connect(album, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Album"); stackedWidget->setCurrentIndex(0); });
	connect(book, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Book"); stackedWidget->setCurrentIndex(0); });
	connect(comic, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Comic"); stackedWidget->setCurrentIndex(0); });
	connect(movie, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Movie"); stackedWidget->setCurrentIndex(0); });
	connect(videogame, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Videogame"); stackedWidget->setCurrentIndex(0); });
    connect(searchbar, &QLineEdit::textChanged, queryProxy, &LibraryQueryFilter::setQuery);
}
