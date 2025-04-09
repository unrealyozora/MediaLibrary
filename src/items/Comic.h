#ifndef COMIC_H
#define COMIC_H
#include "AbstractItem.h"

class Comic:public AbstractItem {
    private:
        std::string author;
        unsigned int chapters;
    public:
        Comic(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& author, unsigned int chapters);
        const std::string& getAuthor() const;
        void setAuthor(const std::string& dir);
        const unsigned int& getChapters() const;
        void setChapters(const unsigned int& len);
        void accept(ItemVisitor& iv) override;
};


#endif