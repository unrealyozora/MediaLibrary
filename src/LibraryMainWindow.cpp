#include "LibraryMainWindow.h"
//aggiungere define come serve
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
/*---------------------------CREAZIONE WIDGET-------------------------------*/

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