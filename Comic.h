#ifndef COMIC_H
#define COMIC_H
#include <AbstractItem.h>

class Comic:public AbstractItem {
    private:
        std::string author;
        unsigned int chapters;
        static constexpr mediatype type = mediatype::Comic;
    protected:
        Comic(std::string _title, unsigned int _year, std::string _description, std::string _genre, std::string _country, std::string author, unsigned int chapters);

    public:

        const std::string getAuthor() const;
        void setAuthor(const std::string& dir);
        const unsigned int getChapters() const;
        void setChapters(unsigned int& len);
};


#endif