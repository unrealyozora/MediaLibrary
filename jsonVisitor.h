#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H

class Album;
class Books;
class Comic;
class Movie;
class Videogames;

class jsonVisitor{
public:
    virtual void visit(Album& album);
    virtual void visit(Books& book);
    virtual void visit(Comic& comic);
    virtual void visit(Movie& movie);
    virtual void visit(Videogames& videogame);

};
#endif