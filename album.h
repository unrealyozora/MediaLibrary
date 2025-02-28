#ifndef ITEM_ALBUM_H
#define ITEM_ALBUM_H
#include <AbstractItem.h>
class Album : public AbstractItem {
private:
	std::string author;
	unsigned int songs;
	unsigned int length;
public:
	Album(std::string _author, unsigned int _songs, unsigned int _length);
	const std::string getAuthor() const ;
	void setAuthor(const std::string& a);
	const unsigned int getLength() const;
	void setLength(const unsigned int l);
	const unsigned int getSongs() const ;
	void setSongs(const unsigned int s);
};

#endif
