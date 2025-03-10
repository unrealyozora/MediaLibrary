#include "LibraryModel.h"
#include <QDebug>
LibraryModel::LibraryModel(QObject* parent): QAbstractTableModel(parent) {}

void LibraryModel::setItems(const QList<std::shared_ptr<AbstractItem>>& _items) {
    beginResetModel();
    items = _items;
    endResetModel();
    qDebug() << "setItems() chiamato. Numero di elementi nella lista:" << items.size();
}
int LibraryModel::rowCount(const QModelIndex& parent) const {
    qDebug() << "rowCount chiamato, elementi nella lista:" << items.size();
    Q_UNUSED(parent);
    return items.size();
}

int LibraryModel::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return 6;  
}

QVariant LibraryModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= items.size())
        return QVariant();

    const std::shared_ptr <AbstractItem> item = items.at(index.row());
    if (!item)
        return QVariant();

    if (role == Qt::DisplayRole) {
        qDebug() << "Richiesta dato per riga:" << index.row() << "colonna:" << index.column();
        switch (index.column()) {
        case 0: return item->getTitle().c_str();
        case 1: return item->getDescription().c_str();
        case 2: return item->getGenre().c_str();
        case 3: return item->getYear();
        case 4: return item->getCountry().c_str();
        case 5: return item->getImage().c_str();
        default: return QVariant();
        }
    }
    return QVariant();
}

QVariant LibraryModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return "Title";
        case 1: return "Description";
        case 2: return "Genre";
        case 3: return "Year";
        case 4: return "Country";
        case 5: return "Image";
        }
    }
    return QVariant();
}

Qt::ItemFlags LibraryModel::flags(const QModelIndex& index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool LibraryModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (!index.isValid() || index.row() >= items.size())
        return false;

    std::shared_ptr <AbstractItem> item = items.at(index.row());
    if (!item)
        return false;

    if (role == Qt::EditRole) {
        switch (index.column()) {
        case 0: item->setTitle(value.toString().toStdString()); break;
        case 1: item->setDescription(value.toString().toStdString()); break;
        case 2: item->setGenre(value.toString().toStdString()); break;
        case 3: item->setYear(value.toInt()); break;
        case 4: item->setCountry(value.toString().toStdString()); break;
        case 5: item->setImage(value.toString().toStdString()); break;
        default: return false;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}