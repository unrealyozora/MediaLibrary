#include "LibraryModelFilter.h"
#include "LibraryListModel.h"
void LibraryModelFilter::setFilterCategory(const QString& category){
		setFilterEnabled(true);
		filterCategory = category;
		invalidateFilter();
}

bool LibraryModelFilter::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const {
	if (!isFilterEnabled()){
		return true;
	}else{
		QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
		QString itemText = sourceModel()->data(index, LibraryListModel::CategoryRole).toString();
		return itemText.contains(filterCategory, Qt::CaseInsensitive);
	}
		
}
bool LibraryModelFilter::isFilterEnabled() const{
	return isEnabled;
}

void LibraryModelFilter::setFilterEnabled(bool x){
	isEnabled=x;
	invalidateFilter();
}
