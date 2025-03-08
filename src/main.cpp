#include <QApplication>
#include <QTableView>
#include "library/library.h"
#include "view/LibraryModel.h"
#include "items/AbstractItem.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Library library;
    LibraryModel model;

    // Collegamento: quando la Library cambia, il modello si aggiorna
    QObject::connect(&library, &Library::itemsChanged, [&]() {
        model.setItems(library.getList());
        });

    // Aggiungiamo alcuni elementi di esempio
    QString path = "assets/prova.json";
    library.fromJson(path);
    model.setItems(library.getList());
    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    return app.exec();
}