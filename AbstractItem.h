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
	const std::string getTitle() const;
	void setTitle(std::string& s);
	const unsigned int getYear() const;
	void setYear(unsigned int& y);
	const std::string getDescription() const;
	void setDescription(std::string s);
	const std::vector<std::string> getGenre() const;
	void setGenre(std::vector<std::string> g);
	const std::string getCountry() const;
	void setCountry(std::string);
};
#endif // !ITEM_ABSTRACT_ITEM_H

