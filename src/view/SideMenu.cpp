#include "SideMenu.h"
#include "LibraryListModel.h"
#include "NewItemForms/AlbumForm.h"
#include "NewItemForms/BookForm.h"
#include "NewItemForms/ComicForm.h"
#include "NewItemForms/MovieForm.h"
#include "NewItemForms/VideogameForm.h"
#include <QFrame>
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
	layout->addSpacing(5);
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

	QMenu* buttonMenu = new QMenu(this);
	QAction* newAlbum = new QAction("Add album", buttonMenu);
	QAction* newBook = new QAction("Add book", buttonMenu);
	QAction* newComic = new QAction("Add comic", buttonMenu);
	QAction* newMovie = new QAction("Add movie", buttonMenu);
	QAction* newVideogame = new QAction("Add videogame", buttonMenu);
	buttonMenu->addAction(newAlbum);
	buttonMenu->addAction(newBook);
	buttonMenu->addAction(newComic);
	buttonMenu->addAction(newMovie);
	buttonMenu->addAction(newVideogame);
	QPushButton* newButton = new QPushButton("New item", this);
	QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
	layout->addSpacing(5);
    layout->addWidget(line);
	all->setChecked(true);
	layout->addSpacing(5);
	layout->addWidget(newButton);
	connect(all, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterEnabled(false); stackedWidget->setCurrentIndex(0); });
	connect(album, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Album"); stackedWidget->setCurrentIndex(0); });
	connect(book, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Book"); stackedWidget->setCurrentIndex(0); });
	connect(comic, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Comic"); stackedWidget->setCurrentIndex(0); });
	connect(movie, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Movie"); stackedWidget->setCurrentIndex(0); });
	connect(videogame, &QPushButton::clicked, this, [categoryProxy, stackedWidget]() {categoryProxy->setFilterCategory("Videogame"); stackedWidget->setCurrentIndex(0); });
    connect(searchbar, &QLineEdit::textChanged, queryProxy, &LibraryQueryFilter::setQuery);

	connect(newButton, &QPushButton::clicked, [newButton, buttonMenu]() { //setta il menu rispetto alla posizione del bottone (da sistemare)
		//buttonMenu->setFixedSize(200, 150);
		QPoint menuPos = newButton->mapToGlobal(newButton->rect().bottomLeft());
		menuPos.setX(menuPos.x() - 100);
		menuPos.setY(menuPos.y() - 150);
		buttonMenu->exec(menuPos);
		});
	

	connect(newAlbum, &QAction::triggered, []() {
		AlbumForm albumForm;
		albumForm.exec();
		});
	connect(newBook, &QAction::triggered, []() {
		BookForm bookForm;
		bookForm.exec();
		});
	connect(newComic, &QAction::triggered, []() {
		ComicForm comicForm;
		comicForm.exec();
		});
	connect(newMovie, &QAction::triggered, []() {
		MovieForm movieForm;
		movieForm.exec();
		});
	connect(newVideogame, &QAction::triggered, []() {
		VideogameForm videogameForm;
		videogameForm.exec();
		});

}
