#include "LibraryVisitor.h"
#include <iostream>
void LibraryVisitor::visitMovie(Movie& m){
	std::cout << "visitor test";
}
