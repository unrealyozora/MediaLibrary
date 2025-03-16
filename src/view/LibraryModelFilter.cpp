#include "LibraryModelFilter.h"

void LibraryModelFilter::setFilterCategory(const QString& category){
		filterCategory = category;
		invalidateFilter();
}

bool LibraryModelFilter::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const {
		QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
		QString itemText = sourceModel()->data(index, Qt::DisplayRole).toString();
		return itemText.contains("Inception", Qt::CaseInsensitive);
}
