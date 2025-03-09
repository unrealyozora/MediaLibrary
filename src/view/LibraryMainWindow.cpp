#include "LibraryMainWindow.h"
#include "../library/library.h"
#include "MainWidget.h"
#include "LibraryListModel.h"
#include <QListView>
#include <QLayout>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
LibraryMainWindow::LibraryMainWindow() {
	LibraryListModel* model = new LibraryListModel();
	QHBoxLayout* mLayout = new QHBoxLayout();
	MainWidget* widget = new MainWidget();
	QListView* listview = new QListView();
	listview->setModel(model);
	listview->setViewMode(QListView::IconMode);  // Mostra solo icone
	listview->setIconSize(QSize(20, 20));      // Dimensioni delle immagini
	listview->setSpacing(50);                    // Spaziatura tra elementi
	listview->setResizeMode(QListView::Adjust);
	listview->setSelectionMode(QAbstractItemView::SingleSelection);

	mLayout->addWidget(widget);
	mLayout->addWidget(listview);
	QWidget* centralWidget = new QWidget();
	centralWidget->setLayout(mLayout);
	this->setCentralWidget(centralWidget);
	QMenuBar* menuBar = new QMenuBar();
	QMenu* fileMenu = new QMenu("File", this);
	menuBar->addMenu(fileMenu);
	QAction* openAction = new QAction("Open", this);
	QAction* exitAction = new QAction("Exit", this);
	fileMenu->addAction(openAction);
	fileMenu->addAction(exitAction);
	connect(openAction, &QAction::triggered, this, &LibraryMainWindow::OpenFile);
	connect(exitAction, &QAction::triggered, this, &QApplication::quit);
	connect(Library::getInstance(), &Library::updateList, model, &LibraryListModel::setItems);
	setMenuBar(menuBar);
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