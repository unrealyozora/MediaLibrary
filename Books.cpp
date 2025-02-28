#include <Books.h>

Books::Books(std::string _author, vector<std::string> _pages, unsigned int _publ_house) : author(_author), pages(_pages), publ_house(_publ_house) {};

Books::~Books() {};

const std::string Books::getAuthor() const {
	return author;
}
void Books::setAuthor(const std::string& auth) {
	this->author = auth;
}
const unsigned int Books::getPages() const {
	return pages;
}
void Books::setPages(unsigned int& pag) {
	this->pages = pag;
}
const unsigned int Books::getPub() const {
	return publ_house;
}
void Books::setPub(unsigned int& pub) {
	this->publ_house = pub;
}