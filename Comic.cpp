#include <Comic.h>

Comic::Comic(std::string _author, vector<std::string> _genre, unsigned int _chapters): author(_author), chapters(_chapters){};

Comic::~Comic() {};

const std::string Comic::getAuthor() const{
	return author;
}
void Comic::setAuthor(const std::string& s) {
	this->author = s;
}
const unsigned int Comic::getChapters() const {
	return chapters;
}
void Comic::setChapters(unsigned int& y) {
	this->chapters = y;
}