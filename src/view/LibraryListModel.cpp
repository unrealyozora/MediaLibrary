#include "LibraryListModel.h"
#include "../items/album.h"  
#include "../items/Books.h"  
#include "../items/Comic.h"  
#include "../items/movie.h"  
#include "../items/Videogames.h"
#include <QScreen>
#include <QApplication>
#include <QDebug>
LibraryListModel::LibraryListModel(QObject* parent):QAbstractListModel(parent) {}

void LibraryListModel::setItems(const QList <std::shared_ptr<AbstractItem>>& _items) {
    beginResetModel();
    this->items = _items;
    endResetModel();
}


int LibraryListModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return this->items.count();
    
}

QVariant LibraryListModel::data(const QModelIndex& index, int role) const {

    if (!index.isValid() || index.row() >= items.size())
        return QVariant();

    if (role == Qt::DecorationRole) {  // Usa DecorationRole per mostrare l'immagine
        QPixmap image(LibraryListModel::items.at(index.row())->getImage().c_str());
        QScreen *screen = QApplication::primaryScreen();
        QRect screenGeometry = screen->availableGeometry();
        QSize availableSize = screenGeometry.size()/4;
            if (image.isNull()) {
                return QPixmap("assets/noImage.jpg").scaled(availableSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            }
            else{
                QSize scaledSize = image.scaled(availableSize, Qt::KeepAspectRatio, Qt::SmoothTransformation).size();
                return image.scaled(scaledSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            }
    }
    else if (role == Qt::DisplayRole) {
        return items.at(index.row())->getTitle().c_str();
    }
    else if (role==Roles::CategoryRole){
        if (dynamic_cast<Album*>(const_cast<AbstractItem*>((items.at(index.row())).get()))){
            return "Album";
        }else if (dynamic_cast<Books*>(const_cast<AbstractItem*>((items.at(index.row())).get()))){
            return "Book";
        }else if (dynamic_cast<Comic*>(const_cast<AbstractItem*>((items.at(index.row())).get()))){
            return "Comic";
        }else if (dynamic_cast<Movie*>(const_cast<AbstractItem*>((items.at(index.row())).get()))){
            return "Movie";
        }else if (dynamic_cast<Videogames*>(const_cast<AbstractItem*>((items.at(index.row())).get()))){
            return "Videogame";
        }
    }
    else if (role == Qt::UserRole) {
        return QVariant::fromValue((items.at(index.row())).get());
    }

    return QVariant();
}
