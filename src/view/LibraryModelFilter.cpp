#include "LibraryModelFilter.h"
#include "LibraryListModel.h"
void LibraryModelFilter::setFilterCategory(const QString& category){
		filterCategory = category;
		invalidateFilter();
}

bool LibraryModelFilter::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const {
	if (!isFilterEnabled()){
		return true;
	}else{
		QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
		QString itemText = sourceModel()->data(index, LibraryListModel::CategoryRole).toString();
		return itemText.contains("Album", Qt::CaseInsensitive);
	}
		
}
bool LibraryModelFilter::isFilterEnabled() const{
	return isEnabled;
}

void LibraryModelFilter::setFilterEnabled(bool enabled){
	if( m_IsFilterEnabled != true ){
           isEnabled = true;
           this->invalidate();
    }
}