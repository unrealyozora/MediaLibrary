#ifndef COMIC_H
#define COMIC_H

#include <string>
#include <vector>

class Comic {
    private:
        std::string author;
        unsigned int chapters;
    protected:
        Comic(std::string author, std::vector<std::string> genre, unsigned int chapters);

    public:

        const std::string getAuthor() const;
        void setAuthor(const std::string& dir);
        const unsigned int getChapters() const;
        void setChapters(unsigned int& len);
};


#endif