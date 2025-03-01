#ifndef ITEM_VISITOR_H
#define ITEM_VISITOR_H

class Movie;

class ItemVisitor {
public:
	virtual ~ItemVisitor() {};
	virtual void visitMovie(Movie& m)=0;
};
#endif
