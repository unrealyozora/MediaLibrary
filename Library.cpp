#include "Library.h"

const unsigned int Library::getSize() const {
	return media.size();
}

const bool Library::is_empty() const {
	return media.empty();
}
/*-------------------------------------------------------NUOVA AGGIUNTA-------------------------------------------------------*/
/*void Library::addItem(std::shared_ptr<AbstractItem> item) {
	media.push_back(item);
}*/
/*----------------------------------------------------------------------------------------------------------------------------*/