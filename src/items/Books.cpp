#include "Books.h"

Books::Books(std::string& _title, unsigned int _year, std::string& _description, std::string& _genre, std::string& _country, const std::string& _image, std::string& _author, unsigned int _pages, std::string& _publ_house)
	:AbstractItem(_title, _year, _description, _genre, _country, _image), author(_author), pages(_pages), publ_house(_publ_house) {}


const std::string& Books::getAuthor() const {
	return author;
}
void Books::setAuthor(const std::string& auth) {
	this->author = auth;
}
const unsigned int Books::getPages() const {
	return pages;
}
void Books::setPages(const unsigned int& pag) {
	this->pages = pag;
}
const std::string& Books::getPub() const {
	return publ_house;
}
void Books::setPub(const std::string& b) {
	this->publ_house = b;
}

void Books::accept(ItemVisitor& iv) {
	iv.visit(*this);
}
