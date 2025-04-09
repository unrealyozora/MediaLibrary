#include <QApplication>
#include <QPalette>
#include <QStyleFactory>
#include <QMainWindow>
#include "library/Library.h"
#include "items/AbstractItem.h"
#include "view/LibraryListModel.h"
#include "view/LibraryMainWindow.h"
int main(int argc, char* argv[]) {
    
    QApplication app(argc, argv);
    
    qRegisterMetaType<AbstractItem*>("AbstractItem*");
    //creazione MainWindow
    LibraryMainWindow* window = new LibraryMainWindow();

    window->resize(1024, 512);
    window->show();

    return app.exec();
}