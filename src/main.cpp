#include <QApplication>

#include <QMainWindow>
#include "library/Library.h"
#include "items/AbstractItem.h"
#include "view/LibraryListModel.h"
#include "view/LibraryMainWindow.h"
int main(int argc, char* argv[]) {

    Library* library = Library::getInstance();
    QApplication app(argc, argv);
    

    //creazione MainWindow
    LibraryMainWindow* window = new LibraryMainWindow();
    //creazione Modello
    
    
    //creazione layout orizzontale
    
    

    

    

    //creazione vista
    
    
    window->resize(1024, 512);
    window->show();

    return app.exec();
}