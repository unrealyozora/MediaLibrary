#ifndef ITEM_MOVIE_H
#define ITEM_MOVIE_H
#include <AbstractItem.h>
class Movie: public AbstractItem {
private:
	std::string director;
	std::string screenwriter;
	unsigned int length;
	std::string production_company;
	static constexpr mediatype type = mediatype::Movie;
public:
	Movie(std::string _title, unsigned int _year, std::string _description, std::string _genre, std::string _country, std::string _director, std::string _screenwriter, unsigned int length, std::string _production_company);
	const std::string getDirector() const;
	void setDirector(const std::string& d);
	const std::string getScreenwriter() const;
	void setScreenwriter(const std::string& s);
	const unsigned int getLength() const;
	void setLength(const unsigned int l);
	const std::string getProd() const;
	void setProd(const std::string p);
	virtual void accept(ItemVisitor& visitor);

};
#endif

