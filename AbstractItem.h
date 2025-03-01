#ifndef ITEM_ABSTRACT_ITEM_H
#define ITEM_ABSTRACT_ITEM_H
#include <string>
#include <vector>
#include <ItemVisitor.h>
class AbstractItem {
private:
	std::string title;
	unsigned int year;
	std::string description;
	std::vector<std::string> genre;
	std::string country;
protected:
	//Added default parameters, maybe change later
	AbstractItem(std::string _title = "Default Title", unsigned int _year = 1950, std::string _description = "Default Description", std::vector<std::string> _genre = {}, std::string _country="Italy");
public:
	virtual ~AbstractItem();
	const std::string getTitle() const;
	void setTitle(const std::string& s);
	const unsigned int getYear() const;
	void setYear(unsigned int& y);
	const std::string getDescription() const;
	void setDescription(const std::string& s);
	const std::vector<std::string> getGenre() const;
	void setGenre(const std::vector<std::string>& g);
	const std::string getCountry() const;
	void setCountry(const std::string& c);
	virtual void accept(ItemVisitor& iv)=0;
};
#endif // !ITEM_ABSTRACT_ITEM_H

