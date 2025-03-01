#include "Library.h"

const unsigned int Library::getSize() const {
	return media.size();
}

const bool Library::is_empty() const {
	return media.empty();
}

QList<std::shared_ptr<AbstractItem>> Library::getList() {
	return media;
}

void Library::addItem(std::shared_ptr<AbstractItem> item) {
	media.push_back(item);
}

void Library::removeItem(std::string title, unsigned int year) {
	for (int x = 0; x < media.size(); x++) {
		if (media[x]->getTitle() == title && media[x]->getYear() == year) {
			media.removeAt(x);
		}
	}
}
