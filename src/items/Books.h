#ifndef BOOKS_H
#define BOOKS_H
#include "AbstractItem.h"
class Books: public AbstractItem{
	private:
		std::string author;
		unsigned int pages;
		std::string publ_house;
		static constexpr mediatype type = mediatype::Book;
	public:
		Books(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _author, unsigned int _pages, const std::string& _publ_house);
		const std::string& getAuthor() const;
		void setAuthor(const std::string& auth);
		const unsigned int getPages() const;
		void setPages(const unsigned int& pag);
		const std::string& getPub() const;
		void setPub(const std::string& pub);
		virtual void accept(ItemVisitor& iv) override;
};

#endif