#include <movie.h>

Movie::Movie(std::string _director, std::string _screenwriter, unsigned int _length, std::string _production_company) :
	director(_director), screenwriter(_screenwriter), length(_length), production_company(_production_company) {
};
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
