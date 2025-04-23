#include "Videogames.h"

Videogames::Videogames(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _developer, bool _multiplayer)
	:AbstractItem(_title, _year, _description, _genre, _country, _image), developer(_developer), multiplayer(_multiplayer){};


const std::string& Videogames::getDeveloper() const {
	return developer;
}
void Videogames::setDeveloper(const std::string& dev) {
	this->developer = dev;
}
bool Videogames::getMultiplayer() const {
	return multiplayer;
}
void Videogames::setMultiplayer(bool mult) {
	this->multiplayer = mult;
}

void Videogames::accept(ItemVisitor& iv) {
	iv.visit(*this);
}



