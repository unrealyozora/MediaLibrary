#include "LibraryListModel.h"
#include "../items/Album.h"  
#include "../items/Books.h"  
#include "../items/Comic.h"  
#include "../items/Movie.h"  
#include "../items/Videogames.h"

LibraryListModel::LibraryListModel(QObject* parent):QAbstractListModel(parent) {}

void LibraryListModel::setItems(const QList <std::shared_ptr<AbstractItem>>& _items) {
    beginResetModel();
    this->items = _items;
    endResetModel();
}

int LibraryListModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    /*return this->items.count();*/
    if (currentCategory == "All") {
        return items.count();
    }

    int count = 0;
    for (const auto& item : items) {
        if ((currentCategory == "Album" && dynamic_cast<Album*>(item.get())) ||
            (currentCategory == "Book" && dynamic_cast<Books*>(item.get())) ||
            (currentCategory == "Comic" && dynamic_cast<Comic*>(item.get())) ||
            (currentCategory == "Movie" && dynamic_cast<Movie*>(item.get())) ||
            (currentCategory == "Videogame" && dynamic_cast<Videogames*>(item.get()))) {
            count++;
        }
    }
    return count;
}

/*QVariant LibraryListModel::data(const QModelIndex& index, int role) const {

    if (!index.isValid() || index.row() >= items.size())
        return QVariant();

    if (role == Qt::DecorationRole) {  // Usa DecorationRole per mostrare l'immagine
        return QPixmap(LibraryListModel::items.at(index.row())->getImage().c_str())
            .scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    else if (role == Qt::DisplayRole) {
        return items.at(index.row())->getTitle().c_str();
    }

    return QVariant();
}*/
/*-------------------------------------------------------------------*/
QVariant LibraryListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();

    QList<std::shared_ptr<AbstractItem>> filteredItems;
    for (const auto& item : items) {
        if (currentCategory == "All" ||
            (currentCategory == "Album" && dynamic_cast<Album*>(item.get())) ||
            (currentCategory == "Book" && dynamic_cast<Books*>(item.get())) ||
            (currentCategory == "Comic" && dynamic_cast<Comic*>(item.get())) ||
            (currentCategory == "Movie" && dynamic_cast<Movie*>(item.get())) ||
            (currentCategory == "Videogame" && dynamic_cast<Videogames*>(item.get()))) {
            filteredItems.append(item);
        }
    }

    if (index.row() >= filteredItems.size())
        return QVariant();

    if (role == Qt::DecorationRole) {
        return QPixmap(filteredItems.at(index.row())->getImage().c_str())
            .scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    return QVariant();
}
/*-------------------------------------------------------------------*/

/*-------------------------------------------------------------------*/
void LibraryListModel::filterByCategory(const QString& category) {
    beginResetModel();
    currentCategory = category;
    endResetModel();
}
/*-------------------------------------------------------------------*/

