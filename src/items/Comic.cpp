#include "Comic.h"

Comic::Comic(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _author, unsigned int _chapters)
	:AbstractItem(_title, _year, _description, _genre, _country, _image), author(_author), chapters(_chapters){}


const std::string& Comic::getAuthor() const{
	return author;
}
void Comic::setAuthor(const std::string& dir) {
	this->author = dir;
}
const unsigned int& Comic::getChapters() const {
	return chapters;
}
void Comic::setChapters(const unsigned int& len) {
	this->chapters = len;
}

void Comic::accept(ItemVisitor& iv) {
	iv.visit(*this);
}
