#include <Comic.h>

Comic::Comic(std::string _title, unsigned int _year, std::string _description, std::string _genre, std::string _country, std::string _author, unsigned int _chapters)
	:AbstractItem(_title, _year, _description, _genre, _country), author(_author), chapters(_chapters){}


const std::string Comic::getAuthor() const{
	return author;
}
void Comic::setAuthor(const std::string& dir) {
	this->author = dir;
}
const unsigned int Comic::getChapters() const {
	return chapters;
}
void Comic::setChapters(unsigned int& len) {
	this->chapters = len;
}

void Comic::accept(ItemVisitor& iv) {
	iv.visit(*this);
}
