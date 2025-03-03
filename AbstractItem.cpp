#include <AbstractItem.h>

AbstractItem::AbstractItem(std::string _title, unsigned int _year, std::string _description, std::string _genre, std::string _country) :
	title(_title), year(_year), description(_description), genre(_genre), country(_country) {}
AbstractItem::~AbstractItem() {}

const std::string AbstractItem::getTitle() const {
	return title;
}
void AbstractItem::setTitle(const std::string& s) {
	this->title = s;
}
const unsigned int AbstractItem::getYear() const {
	return year;
}
void AbstractItem::setYear(unsigned int& y) {
	this->year = y;
}
const std::string AbstractItem::getDescription() const {
	return description;
}
void AbstractItem::setDescription(const std::string& s) {
	this->description = s;
}
const std::string AbstractItem::getGenre() const {
	return genre;
}
void AbstractItem::setGenre(const std::string& g) {
	this->genre = g;
}
const std::string AbstractItem::getCountry() const {
	return country;
}
void AbstractItem::setCountry(const std::string& c) {
	this->country = c;
}
