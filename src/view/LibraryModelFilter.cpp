#include "LibraryModelFilter.h"
#include "LibraryListModel.h"
LibraryCategoryFilter::LibraryCategoryFilter(QObject* parent) : QSortFilterProxyModel(parent){
}
void LibraryCategoryFilter::setFilterCategory(const QString& category){
		setFilterEnabled(true);
		filterCategory = category;
		invalidateFilter();
}

bool LibraryCategoryFilter::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const {
	if (!isFilterEnabled()){
		return true;
	}else{
		QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
		QString itemText = sourceModel()->data(index, LibraryListModel::CategoryRole).toString();
		return itemText.contains(filterCategory, Qt::CaseInsensitive);
		
	}
		
}
bool LibraryCategoryFilter::isFilterEnabled() const{
	return isEnabled;
}

void LibraryCategoryFilter::setFilterEnabled(bool x){
	isEnabled=x;
	invalidateFilter();
}


bool LibraryQueryFilter::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const{
	if (query.isEmpty()) {
		return true;
	}
	else {
		QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
		QString name = sourceModel()->data(index, Qt::DisplayRole).toString();
		return name.contains(query, Qt::CaseInsensitive);
	}
}

LibraryQueryFilter::LibraryQueryFilter(QObject* parent):QSortFilterProxyModel(parent){}

void LibraryQueryFilter::setQuery(const QString& newQuery) {
	query = newQuery;
	invalidateFilter();
}
