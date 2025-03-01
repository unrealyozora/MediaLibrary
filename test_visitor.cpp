#include <AbstractItem.h>
#include <Library.h>
#include <LibraryVisitor.h>
#include <movie.h>
#include <iostream>
static void test() {
	Library* l = new Library();
	LibraryVisitor* visitor = new LibraryVisitor();
	Movie* prova = new Movie("Scorsese", "Scorsese2", 120, "Universal");
	prova->accept(*visitor);
}