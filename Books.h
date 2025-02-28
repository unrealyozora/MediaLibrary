#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <vector>

namespace std::string {
	class Books {
	private:
		string author;
		unsigned int pages;
		string publ_house;
	protected:
		Books(string author, unsigned int pages, string publ_house);
	public:
		virtual ~Books();
		const string getAuthor() const;
		void setAuthor(string& auth);
		const unsigned int getPages() const;
		void setPages(unsigned int& pag);
		const string getPub() const;
		void setPub(string pub);
	};
}
#endif