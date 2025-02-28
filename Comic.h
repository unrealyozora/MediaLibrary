#ifndef COMIC_H
#define COMIC_H

#include <string>
#include <vector>

namespace std::string {

    class Comic {
    private:
        string author;
        unsigned int chapters;
    protected:
        Comic(string author, vector<string> genre, unsigned int chapters);

    public:
        virtual ~Comic();

        const string getAuthor() const;
        void setAuthor(string& dir);
        const unsigned int getChapters() const;
        void setChapters(unsigned int& len);
    };

}

#endif