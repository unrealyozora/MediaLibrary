#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include "AbstractItem.h"

class Videogames:public AbstractItem {
	private:
		std::string developer;
		bool multiplayer;
	public:
		Videogames(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _developer, bool _multiplayer);
		const std::string& getDeveloper() const;
		void setDeveloper(const std::string& dev);
		const unsigned int getMultiplayer() const;
		void setMultiplayer(const bool mult);
		virtual void accept(ItemVisitor& iv) override;
};
#endif