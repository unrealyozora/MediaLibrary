#ifndef BOOKS_H
#define BOOKS_H
#include <AbstractItem.h>
class Books: public AbstractItem{
	private:
		std::string author;
		unsigned int pages;
		std::string publ_house;
		static constexpr mediatype type = mediatype::Book;
	protected:
		Books(std::string _title, unsigned int _year, std::string _description, std::string _genre, std::string _country, std::string _author, unsigned int _pages, std::string _publ_house);
	public:
		const std::string getAuthor() const;
		void setAuthor(const std::string& auth);
		const unsigned int getPages() const;
		void setPages(unsigned int& pag);
		const std::string getPub() const;
		void setPub(const std::string& pub);
};

#endif