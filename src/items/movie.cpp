#include "Movie.h"

Movie::Movie(std::string _title, unsigned int _year, std::string _description, std::string _genre, std::string _country,  std::string _director, std::string _screenwriter, unsigned int _length, std::string _production_company)
	: AbstractItem(_title, _year, _description, _genre, _country), director(_director), screenwriter(_screenwriter), length(_length), production_company(_production_company) {
}

const std::string Movie::getDirector() const {
	return director;
}

void Movie::setDirector(const std::string& d) {
	this->director = d;
}

const std::string Movie::getScreenwriter() const {
	return screenwriter;
}

void Movie::setScreenwriter(const std::string& s) {
	this->screenwriter = s;
}

const unsigned int Movie::getLength() const {
	return length;
}

void Movie::setLength(const unsigned int l) {
	this->length = l;
}

const std::string Movie::getProd() const {
	return production_company;
}

void Movie::setProd(const std::string p) {
	this->production_company = p;
}

void Movie::accept(ItemVisitor& iv) {
	iv.visit(*this);
}



