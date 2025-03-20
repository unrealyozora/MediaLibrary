#include "LibraryMainWindow.h"
#include "LibraryMainWindow.h"
#include "../library/Library.h"
#include "ThumbnailDelegate.h"
#include "SideMenu.h"
#include "ItemDetailWidget.h"
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
	stackedWidget = new QStackedWidget(this);
    model = new LibraryListModel(this);
	categoryFilter = new LibraryCategoryFilter(this);
	queryFilter = new LibraryQueryFilter(this);
    SideMenu* sideMenu = new SideMenu(categoryFilter, queryFilter, stackedWidget);
    QListView* listview = new QListView(this);
    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout* MainLayout = new QHBoxLayout();
	ThumbnailDelegate* thumbnaildelegate = new ThumbnailDelegate(listview);
	detailWidget = new ItemDetailsWidget(this);
	

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
    MainLayout->addWidget(sideMenu);
    MainLayout->addWidget(stackedWidget);
    centralWidget->setLayout(MainLayout);
    this->setCentralWidget(centralWidget);

    connect(openAction, &QAction::triggered, this, &LibraryMainWindow::OpenFile); //Finestra di dialogo apertura file
	connect(saveAction, &QAction::triggered, this, &LibraryMainWindow::SaveFile);
	connect(exitAction, &QAction::triggered, this, &QApplication::quit); // Uscita dall' applicazione
	connect(Library::getInstance(), &Library::updateList, model, &LibraryListModel::setItems); // Aggiornamento modello
	connect(listview, &QListView::clicked, this, &LibraryMainWindow::itemSelected);
	connect(detailWidget, &ItemDetailsWidget::backToHome, this, &LibraryMainWindow::backHome);
}


void LibraryMainWindow::OpenFile() {
		QString filepath = QFileDialog::getOpenFileName(this, "Select a file", "", "Library File (*.json *.xml);;Tutti i file (*.*)");
		if (!filepath.isEmpty()) {
			if (filepath.endsWith(".json", Qt::CaseInsensitive)) {
				categoryFilter->setFilterEnabled(false);
				Library::getInstance()->fromJson(filepath);
				
			}
			else if (filepath.endsWith(".xml", Qt::CaseInsensitive)) {
				Library::getInstance()->fromXml(filepath);
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
				Library::getInstance()->toJson(filepath);
			}else if (selectedFilter.contains("*.xml")){
				filepath+=".xml";
				Library::getInstance()->toXml(filepath);
			}
		}else{
			if (filepath.endsWith(".json", Qt::CaseInsensitive)){
				Library::getInstance()->toJson(filepath);
			}else if (filepath.endsWith(".xml", Qt::CaseInsensitive)){
				Library::getInstance()->toXml(filepath);
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
