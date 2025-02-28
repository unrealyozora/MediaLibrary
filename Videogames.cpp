#include <Videogames.h>

Videogames::Videogames(std::string _author, vector<std::string> _pages, unsigned int _publ_house) : author(_author), pages(_pages), publ_house(_publ_house) {};

Videogames::~Videogames() {};

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
