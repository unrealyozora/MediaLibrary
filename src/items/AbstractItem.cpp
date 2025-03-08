#include "AbstractItem.h"

AbstractItem::AbstractItem(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image) :
	title(_title), year(_year), description(_description), genre(_genre), country(_country), image(_image) {}
AbstractItem::~AbstractItem() {}

const std::string& AbstractItem::getTitle() const {
	return title;
}
void AbstractItem::setTitle(const std::string& s) {
	this->title = s;
}
const unsigned int AbstractItem::getYear() const {
	return year;
}
void AbstractItem::setYear(const unsigned int& y) {
	this->year = y;
}
const std::string& AbstractItem::getDescription() const {
	return description;
}
void AbstractItem::setDescription(const std::string& s) {
	this->description = s;
}
const std::string& AbstractItem::getGenre() const {
	return genre;
}
void AbstractItem::setGenre(const std::string& g) {
	this->genre = g;
}
const std::string& AbstractItem::getCountry() const {
	return country;
}
void AbstractItem::setCountry(const std::string& c) {
	this->country = c;
}

const std::string& AbstractItem::getImage() const {
	return image;
}

void AbstractItem::setImage(const std::string& i) {
	this->image = i;
}

