#ifndef VIEW_TABLE_MODEL_H
#define VIEW_TABLE_MODEL_H
#include <QAbstractTableModel>
#include "../items/AbstractItem.h"
#include <memory>
class LibraryModel : public QAbstractTableModel {
	Q_OBJECT
private:
	QList<std::shared_ptr<AbstractItem>> items;
public:
	explicit LibraryModel(QObject* parent = nullptr);
	void setItems(const QList<std::shared_ptr<AbstractItem>> & _items);
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
};
#endif
