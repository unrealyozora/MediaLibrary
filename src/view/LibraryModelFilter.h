#ifndef VIEW_LIBRARY_FILTER
#define VIEW_LIBRARY_FILTER
#include <QSortFilterProxyModel>

class LibraryCategoryFilter : public QSortFilterProxyModel {
	Q_OBJECT
private:
	QString filterCategory;
	bool isEnabled;
public:
	explicit LibraryCategoryFilter(QObject* parent = nullptr);
	void setFilterCategory(const QString& category);
	bool isFilterEnabled() const;
	void setFilterEnabled(bool x);
protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;
};

class LibraryQueryFilter : public QSortFilterProxyModel {
	Q_OBJECT
private:
	QString query;
protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;
public:
	LibraryQueryFilter(QObject* parent = nullptr);
	void setQuery(const QString& newQuery);
};
#endif
