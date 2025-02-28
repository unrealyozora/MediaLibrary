#ifndef ITEM_ABSTRACT_ITEM_H
#define ITEM_ABSTRACT_ITEM_H
#include <string>
#include <vector>
class AbstractItem {
private:
	std::string Title;
	unsigned int Year;
	std::string Description;
	std::vector<std::string> Genre;
	std::string Country;
protected:
	AbstractItem(std::string Title, unsigned int Year, std::string Description, std::vector<std::string> Genre, std::string Country);
public:
	virtual ~AbstractItem();
	std::string getTitle();
	void setTitle(std::string& s);
	unsigned int getYear();
	void setYear(unsigned int& y);
	std::string getDescription();
	void setDescription(std::string s);
	std::vector<std::string> getGenre();
	void setGenre(std::vector<std::string> g);
	std::string getCountry();
	void setCountry(std::string);
};
#endif // !ITEM_ABSTRACT_ITEM_H

