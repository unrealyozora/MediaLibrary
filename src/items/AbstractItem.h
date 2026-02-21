#ifndef ITEM_ABSTRACT_ITEM_H
#define ITEM_ABSTRACT_ITEM_H
#include <string>
#include <vector>
#include <QMetaType>
#include "ItemVisitor.h"
class AbstractItem {
private:
	std::string title;
	unsigned int year;
	std::string description;
	std::string genre;
	std::string country;
	std::string image;
	unsigned int viewCount;
public:
	AbstractItem(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image);
	virtual ~AbstractItem();
	const std::string& getTitle() const;
	void setTitle(const std::string& s);
	const unsigned int& getYear() const;
	void setYear(const unsigned int& y);
	const std::string& getDescription() const;
	void setDescription(const std::string& s);
	const std::string& getGenre() const;
	void setGenre(const std::string& g);
	const std::string& getCountry() const;
	void setCountry(const std::string& c);
	const std::string& getImage() const;
	void setImage(const std::string& i);
	unsigned int getViewCount() const;
	void setViewCount(unsigned int vc);
	void incrementViewCount();

	virtual void accept(ItemVisitor& iv) = 0;
};
Q_DECLARE_METATYPE(AbstractItem*) //necessario affinch� LibraryListModel possa restituire un QVariant con il puntatore ad un AbstractItem
#endif // !ITEM_ABSTRACT_ITEM_H