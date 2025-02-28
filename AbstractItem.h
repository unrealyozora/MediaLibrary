#ifndef ITEM_ABSTRACT_ITEM_H
#define ITEM_ABSTRACT_ITEM_H
#include <string>
#include <vector>
class AbstractItem {
private:
	std::string title;
	unsigned int year;
	std::string description;
	std::vector<std::string> genre;
	std::string country;
protected:
	AbstractItem(std::string _title, unsigned int _year, std::string _description, std::vector<std::string> _genre, std::string _country);
public:
	virtual ~AbstractItem();
	const std::string getTitle() const;
<<<<<<< HEAD
	void setTitle(const std::string& s);
	const unsigned int getYear() const;
	void setYear(unsigned int& y);
	const std::string getDescription() const;
	void setDescription(const std::string s);
	const std::vector<std::string> getGenre() const;
	void setGenre(const std::vector<std::string> g);
	const std::string getCountry() const;
	void setCountry(const std::string c);
=======
	void setTitle(std::string& s);
	const unsigned int getYear() const;
	void setYear(unsigned int& y);
	const std::string getDescription() const;
	void setDescription(std::string s);
	const std::vector<std::string> getGenre() const;
	void setGenre(std::vector<std::string> g);
	const std::string getCountry() const;
	void setCountry(std::string);
>>>>>>> 8ec95786043334a1df7a4ca5b091ba10cf9784ef
};
#endif // !ITEM_ABSTRACT_ITEM_H

