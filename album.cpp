#include "album.h"

Album::Album(std::string _author, unsigned int _songs, unsigned int _length) :author(_author), songs(_songs), length(_length) {};
const std::string Album::getAuthor() const{
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





