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

    /*----------------------------------------------------------------------------------------------------------------------------*/
    /*std::shared_ptr<Library> library = std::make_shared<Library>(); // Creiamo la libreria
    std::shared_ptr<LibraryVisitor> visitor = std::make_shared<LibraryVisitor>();

    std::shared_ptr<Movie> prova = std::make_shared<Movie>("Scorsese", "Scorsese2", 120, "Universal");
    prova->accept(*visitor);
    library->addItem(prova);*/
    /*----------------------------------------------------------------------------------------------------------------------------*/
}