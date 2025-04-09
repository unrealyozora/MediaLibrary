#include "movie.h"

Movie::Movie(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _director, const std::string& _screenwriter, unsigned int _length, const std::string& _production_company)
	: AbstractItem(_title, _year, _description, _genre, _country, _image), director(_director), screenwriter(_screenwriter), length(_length), production_company(_production_company) {
}

const std::string& Movie::getDirector() const {
	return director;
}

void Movie::setDirector(const std::string& d) {
	this->director = d;
}

const std::string& Movie::getScreenwriter() const {
	return screenwriter;
}

void Movie::setScreenwriter(const std::string& s) {
	this->screenwriter = s;
}

const unsigned int& Movie::getLength() const {
	return length;
}

void Movie::setLength(const unsigned int l) {
	this->length = l;
}

const std::string& Movie::getProd() const {
	return production_company;
}

void Movie::setProd(const std::string& p) {
	this->production_company = p;
}

void Movie::accept(ItemVisitor& iv) {
	iv.visit(*this);
}



