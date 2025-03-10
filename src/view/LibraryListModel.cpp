#include "LibraryListModel.h"

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
        return QPixmap(LibraryListModel::items.at(index.row())->getImage().c_str())
            .scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    return QVariant();
}

