#include "LibraryMainWindow.h"
#include "LibraryMainWindow.h"
#include "../library/Library.h"
#include "ThumbnailDelegate.h"
#include "SideMenu.h"
#include "ItemDetailWidget.h"
#include "NewItemForm.h"
#include <QListView>
#include <QLayout>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
LibraryMainWindow::LibraryMainWindow(){
    /*-------------------CREAZIONE MENU BAR-------------------*/
    QMenuBar* menuBar = new QMenuBar();
    QMenu* fileMenu = new QMenu("File", this);
    menuBar->addMenu(fileMenu);
    QAction* openAction = new QAction("Open", this);
	QAction* saveAction = new QAction("Save as", this);
	QAction* exitAction = new QAction("Exit", this);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(exitAction);
    setMenuBar(menuBar);
   /*------------------------CREAZIONE WIDGET-------------------*/
	NewItemForm* itemForm = new NewItemForm(this);
	QPushButton* newButton = new QPushButton("New item", this);
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
	QGridLayout* buttonOverlay = new QGridLayout();
	stackedWidget = new QStackedWidget(this);
    model = new LibraryListModel(this);
	categoryFilter = new LibraryCategoryFilter(this);
	queryFilter = new LibraryQueryFilter(this);
    SideMenu* sideMenu = new SideMenu(categoryFilter, queryFilter, stackedWidget);
	sideMenu->setFixedWidth(225);
    QListView* listview = new QListView(this);
    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout* MainLayout = new QHBoxLayout();
	ThumbnailDelegate* thumbnaildelegate = new ThumbnailDelegate(listview);
	detailWidget = new ItemDetailsWidget(this);
	/*QPalette pal = detailWidget->palette();
	QColor myGray(141, 153, 174);
	pal.setColor(QPalette::Window, myGray);
	detailWidget->setAutoFillBackground(true);
	detailWidget->setPalette(pal);*/
	
	

	categoryFilter->setSourceModel(model);
	queryFilter->setSourceModel(categoryFilter);
	queryFilter->setFilterCaseSensitivity(Qt::CaseInsensitive);
	
	
    listview->setModel(queryFilter);
	listview->setViewMode(QListView::IconMode);  // Mostra solo icone
	listview->setIconSize(QSize(20, 20));      // Dimensioni delle immagini
	listview->setSpacing(50);                    // Spaziatura tra elementi
	listview->setResizeMode(QListView::Adjust);
	listview->setSelectionMode(QAbstractItemView::SingleSelection);
	listview->setItemDelegate(thumbnaildelegate);
	stackedWidget->addWidget(listview);
	stackedWidget->addWidget(detailWidget);
	buttonOverlay->addWidget(stackedWidget, 0, 0);
	buttonOverlay->addWidget(newButton,0,0, Qt::AlignBottom|Qt::AlignRight);
    MainLayout->addWidget(sideMenu);
	MainLayout->addLayout(buttonOverlay);
    //MainLayout->addWidget(buttonOverlay);
    centralWidget->setLayout(MainLayout);
    this->setCentralWidget(centralWidget);

    connect(openAction, &QAction::triggered, this, &LibraryMainWindow::OpenFile); //Finestra di dialogo apertura file
	connect(saveAction, &QAction::triggered, this, &LibraryMainWindow::SaveFile);
	connect(exitAction, &QAction::triggered, this, &QApplication::quit); // Uscita dall' applicazione
	connect(Library::getInstance(), &Library::updateList, model, &LibraryListModel::setItems); // Aggiornamento modello
	connect(listview, &QListView::clicked, this, &LibraryMainWindow::itemSelected);
	connect(detailWidget, &ItemDetailsWidget::backToHome, this, &LibraryMainWindow::backHome);
	connect(newButton, &QPushButton::clicked, [newButton, buttonMenu]() { //setta il menu rispetto alla posizione del bottone (da sistemare)
		//buttonMenu->setFixedSize(200, 150);
		QPoint menuPos = newButton->mapToGlobal(newButton->rect().bottomLeft());
		menuPos.setX(menuPos.x() - 100);
		menuPos.setY(menuPos.y() - 150);
		buttonMenu->exec(menuPos);
		});
	connect(stackedWidget, &QStackedWidget::currentChanged, [newButton](int index) {
		if (index == 0) {
			newButton->show();
		}
		else {
			newButton->hide();
		}
	});
	connect(newAlbum, &QAction::triggered, itemForm, &NewItemForm::initializeAlbumForm);
	connect(newBook, &QAction::triggered, itemForm, &NewItemForm::initializeBookForm);
	connect(newComic, &QAction::triggered, itemForm, &NewItemForm::initializeComicForm);
	connect(newMovie, &QAction::triggered, itemForm, &NewItemForm::initializeMovieForm);
	connect(newVideogame, &QAction::triggered, itemForm, &NewItemForm::initializeVideogameForm);
}


void LibraryMainWindow::OpenFile() {
		QString filepath = QFileDialog::getOpenFileName(this, "Select a file", "", "Library File (*.json *.xml);;Tutti i file (*.*)");
		if (!filepath.isEmpty()) {
			if (filepath.endsWith(".json", Qt::CaseInsensitive)) {
				categoryFilter->setFilterEnabled(false);
				try {
					Library::getInstance()->fromJson(filepath);
				}
				catch (const std::runtime_error& e) {
					QMessageBox error;
					error.setWindowTitle("Error");
					error.setText(e.what());
					error.exec();
				}
				
			}
			else if (filepath.endsWith(".xml", Qt::CaseInsensitive)) {
				try {
					Library::getInstance()->fromXml(filepath);
				}
				catch (const std::runtime_error& e) {
					QMessageBox error;
					error.setWindowTitle("Error");
					error.setText(e.what());
					error.exec();
				}
			}
			else {
				QMessageBox invalidFilemsg;
				invalidFilemsg.setWindowTitle("Error");
				invalidFilemsg.setText("<p align='center'>Invalid library format<br></p>");
				invalidFilemsg.exec();
			}
			
		}
		else {
			qDebug() << "Nessun file selezionato."; //debug only
		}
}

void LibraryMainWindow::SaveFile(){
	QString selectedFilter;
	QString filepath= QFileDialog::getSaveFileName(this, "Save a file", "", "Json File (*.json);;Xml File(*.xml)", &selectedFilter);
	if (!filepath.isEmpty()){
		QFileInfo fileInfo(filepath);
		if (fileInfo.suffix().isEmpty()){
			if (selectedFilter.contains("*.json")){
				filepath+=".json";
				try {
					Library::getInstance()->toJson(filepath);
				}
				catch (std::string& s) {
					qDebug() << "catch savefile entrato";//debug only
					QMessageBox warning;
					warning.setWindowTitle("Warning");
					warning.setText(s.c_str());
					warning.exec();
				}
				catch (const std::runtime_error& e) {
					QMessageBox error;
					error.setWindowTitle("Error");
					error.setText(e.what());
					error.exec();
				}
				
			}else if (selectedFilter.contains("*.xml")){
				filepath+=".xml";
				try {
					Library::getInstance()->toXml(filepath);
				}
				catch (std::string& s) {
					qDebug() << "catch savefile entrato";//debug only
					QMessageBox warning;
					warning.setWindowTitle("Warning");
					warning.setText(s.c_str());
					warning.exec();
				}
				
			}
		}else{
			if (filepath.endsWith(".json", Qt::CaseInsensitive)){
				try {
					Library::getInstance()->toJson(filepath);
				}
				catch (std::string& s) {
					QMessageBox warning;
					warning.setWindowTitle("Warning");
					warning.setText(s.c_str());
					warning.exec();
				}
				catch (const std::runtime_error& e) {
					QMessageBox error;
					error.setWindowTitle("Error");
					error.setText(e.what());
					error.exec();
				}
			}else if (filepath.endsWith(".xml", Qt::CaseInsensitive)){
				try {
					Library::getInstance()->toXml(filepath);
				}
				catch (std::string& s) {
					QMessageBox warning;
					warning.setWindowTitle("Warning");
					warning.setText(s.c_str());
					warning.exec();
				}
			}else{
				QMessageBox invalidFilemsg;
				invalidFilemsg.setWindowTitle("Error");
				invalidFilemsg.setText("<p align='center'>Unsupported file format<br></p>");
				invalidFilemsg.exec();
				
			}
		}
	}
}

void LibraryMainWindow::itemSelected(const QModelIndex& index) {
	qDebug("elemento cliccato");//debug only
	AbstractItem* selectedItem = index.data(Qt::UserRole).value<AbstractItem*>();
	if (selectedItem) {
		qDebug("itemSelected entrato");//debug only
		detailWidget->showDetails(selectedItem);
		stackedWidget->setCurrentIndex(1);
	}
}

void LibraryMainWindow::backHome(){
	stackedWidget->setCurrentIndex(0);
}
