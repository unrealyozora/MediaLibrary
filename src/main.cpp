#include <QApplication>
#include <QPalette>
#include <QStyleFactory>
#include <QMainWindow>
#include "library/Library.h"
#include "items/AbstractItem.h"
#include "view/LibraryListModel.h"
#include "view/LibraryMainWindow.h"
#include "view/StyleSetup.h"
int main(int argc, char* argv[]) {
    
    QApplication app(argc, argv);
    StyleSetup::SetStyle(app); //applica un tema chiaro unico, indipendente dalla piattaforma sulla quale viene eseguito il programma
    Library* library=Library::getInstance();
    qRegisterMetaType<AbstractItem*>("AbstractItem*");
    //creazione MainWindow
    LibraryMainWindow* window = new LibraryMainWindow();

    window->resize(1024, 512);
    window->show();

    return app.exec();
}