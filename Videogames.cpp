#include <Videogames.h>

Videogames::Videogames(std::string _developer, bool _multiplayer) : developer(_developer), multiplayer(_multiplayer){};


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
