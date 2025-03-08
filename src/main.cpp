#include <QApplication>
#include <QTableView>
#include "library/library.h"
#include "view/LibraryModel.h"
#include "items/AbstractItem.h"
#include "view/MainWidget.h"
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget* window = new QWidget();
    Library library;
    LibraryModel model;
    QHBoxLayout* mLayout = new QHBoxLayout(window);
    MainWidget* widget = new MainWidget();
    //widget->show();

    // il signal non è ancora stato implementato
    QObject::connect(&library, &Library::itemsChanged, [&]() {
        model.setItems(library.getList());
        });

    QString path = "assets/prova.json";
    library.fromJson(path);
    model.setItems(library.getList());
    QTableView tableView;
    tableView.setModel(&model);
    //tableView.show();
    mLayout->addWidget(widget);
    mLayout->addWidget(&tableView);
    window->resize(1024, 512);
    window->show();

    return app.exec();
}