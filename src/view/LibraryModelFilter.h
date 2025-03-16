#ifndef VIEW_LIBRARY_FILTER
#define VIEW_LIBRARY_FILTER
#include <QSortFilterProxyModel>

class LibraryModelFilter : public QSortFilterProxyModel {
	Q_OBJECT
private:
	QString filterCategory;
public:
	explicit LibraryModelFilter(QObject* parent = nullptr) : QSortFilterProxyModel(parent) {}
	void setFilterCategory(const QString& category);
protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;
};
#endif
