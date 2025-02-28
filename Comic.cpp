#include <Comic.h>

Comic::Comic(std::string _author, std::vector<std::string> _genre, unsigned int _chapters): author(_author), chapters(_chapters){};


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