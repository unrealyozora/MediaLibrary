#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <vector>

class Books {
	private:
		std::string author;
		unsigned int pages;
		std::string publ_house;
	protected:
		Books(std::string _author, unsigned int _pages, std::string _publ_house);
	public:
		const std::string getAuthor() const;
		void setAuthor(const std::string& auth);
		const unsigned int getPages() const;
		void setPages(unsigned int& pag);
		const std::string getPub() const;
		void setPub(const std::string& pub);
};

#endif