#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <string>
#include <vector>

namespace std::string {
	class Videogames {
	private:
		string developer;
		bool multiplayer;
	protected:
		Videogames(string developer, bool multiplayer);
	public:
		virtual ~Videogames();

		const string getDeveloper() const;
		void setDeveloper(string& dev);
		const unsigned int getMultiplayer() const;
		void setMultiplayer(bool mult);
	};
}
#endif