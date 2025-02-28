#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include <AbstractItem.h>


class Videogames:public AbstractItem {
	private:
		std::string developer;
		bool multiplayer;
	protected:
		Videogames(std::string _developer, bool _multiplayer);
	public:
		const std::string getDeveloper() const;
		void setDeveloper(const std::string& dev);
		const unsigned int getMultiplayer() const;
		void setMultiplayer(const bool mult);
};
#endif