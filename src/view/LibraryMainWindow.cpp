#include "LibraryMainWindow.h"
#include "LibraryMainWindow.h"
#include "../library/Library.h"
#include "SideMenu.h"
#include "LibraryListModel.h"
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
	QAction* exitAction = new QAction("Exit", this);
	fileMenu->addAction(openAction);
	fileMenu->addAction(exitAction);
    setMenuBar(menuBar);
   /*------------------------CREAZIONE WIDGET-------------------*/

    LibraryListModel* model = new LibraryListModel();
    SideMenu* sideMenu = new SideMenu();
    QListView* listview = new QListView();
    QWidget* centralWidget = new QWidget();
    QHBoxLayout* MainLayout = new QHBoxLayout();

    listview->setModel(model);
	listview->setViewMode(QListView::IconMode);  // Mostra solo icone
	listview->setIconSize(QSize(20, 20));      // Dimensioni delle immagini
	listview->setSpacing(50);                    // Spaziatura tra elementi
	listview->setResizeMode(QListView::Adjust);
	listview->setSelectionMode(QAbstractItemView::SingleSelection);

    MainLayout->addWidget(sideMenu);
    MainLayout->addWidget(listview);
    centralWidget->setLayout(MainLayout);
    this->setCentralWidget(centralWidget);

    connect(openAction, &QAction::triggered, this, &LibraryMainWindow::OpenFile); //Finestra di dialogo apertura file
	connect(exitAction, &QAction::triggered, this, &QApplication::quit); // Uscita dall' applicazione
	connect(Library::getInstance(), &Library::updateList, model, &LibraryListModel::setItems); // Aggiornamento modello
}

void LibraryMainWindow::OpenFile() {
		QString filepath = QFileDialog::getOpenFileName(this, "Seleziona un file", "", "Library File (*.json *.xml);;Tutti i file (*.*)");
		if (!filepath.isEmpty()) {
			if (filepath.endsWith(".json", Qt::CaseInsensitive)) {
				qDebug("json");
				Library::getInstance()->fromJson(filepath);
				
			}
			else if (filepath.endsWith(".xml", Qt::CaseInsensitive)) {
				qDebug("xml");
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
			qDebug() << "Nessun file selezionato."; //exception handling da mettere
		}
}