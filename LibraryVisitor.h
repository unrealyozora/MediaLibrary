#ifndef LIBRARY_VISITOR_H
#define LIBRARY_VISITOR_H
#include <movie.h>
class LibraryVisitor:public ItemVisitor {
	void visitMovie(Movie& m);
};

#endif

