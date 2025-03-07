#ifndef ITEM_VISITOR_H
#define ITEM_VISITOR_H

class Album;
class Books;
class Comic;
class Movie;
class Videogames;

class ItemVisitor{
public:
    virtual ~ItemVisitor(){};
    virtual void visit(Album& album)=0;
    virtual void visit(Books& book)=0;
    virtual void visit(Comic& comic)=0;
    virtual void visit(Movie& movie)=0;
    virtual void visit(Videogames& videogame)=0;
};
#endif