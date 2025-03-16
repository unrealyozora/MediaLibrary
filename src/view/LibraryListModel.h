#ifndef VIEW_LIB_MODEL_H
#define VIEW_LIB_MODEL_H
#include <memory>
#include <QList>
#include <QAbstractListModel>
#include <QPixmap>
#include "../items/AbstractItem.h"
class LibraryListModel :public QAbstractListModel {
	Q_OBJECT
private:
	QList<std::shared_ptr<AbstractItem>> items;
public:
	explicit LibraryListModel(QObject* parent = nullptr);
	void setItems(const QList <std::shared_ptr<AbstractItem>>& _items);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	
};
#endif
