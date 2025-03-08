#include "album.h"

Album::Album(const std::string& _title, unsigned int _year , const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _author, unsigned int _songs, unsigned int _length)
	: AbstractItem(_title, _year, _description, _genre, _country, _image), author(_author), songs(_songs), length(_length) {}

const std::string& Album::getAuthor() const{
	return author;
}

void Album::setAuthor(const std::string& a){
	this->author = a;
}

const unsigned int Album::getLength() const {
	return length;
}

void Album::setLength(const unsigned int l) {
	this->length = l;
}

const unsigned int Album::getSongs() const {
	return songs;
}

void Album::setSongs(const unsigned int s) {
	this->songs = s;
}

void Album::accept(ItemVisitor& iv) {
	iv.visit(*this);
}





