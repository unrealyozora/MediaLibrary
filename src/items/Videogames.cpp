#include "Videogames.h"

Videogames::Videogames(std::string _title, unsigned int _year, std::string _description, std::string _genre, std::string _country, const std::string _image, std::string _developer, bool _multiplayer)
	:AbstractItem(_title, _year, _description, _genre, _country, _image), developer(_developer), multiplayer(_multiplayer){};


const std::string Videogames::getDeveloper() const {
	return developer;
}
void Videogames::setDeveloper(const std::string& dev) {
	this->developer = dev;
}
const unsigned int Videogames::getMultiplayer() const {
	return multiplayer;
}
void Videogames::setMultiplayer(bool mult) {
	this->multiplayer = mult;
}

void Videogames::accept(ItemVisitor& iv) {
	iv.visit(*this);
}



