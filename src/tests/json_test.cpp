#include <QString>
#include <iostream>
#include "../library/Library.h"
static void test() {
	QString path_lettura = "C:\\Users\\tomma\\Dev\\MediaLibrary\\assets\\prova.json";
	QString path_scrittura = "C:\\Users\\tomma\\Dev\\MediaLibrary\\assets\\prova_scrittura.json";
	Library* newLib = new Library();
	try {
		newLib->fromJson(path_lettura);
	}
	catch (const std::runtime_error& e) { std::cerr << e.what() << std::endl;
	}

	if (newLib->is_empty()) {
		std::cout << " La lista e' vuota, ziopovero ";
	} else {
		auto x = newLib->getList();
		for (unsigned int i = 0; i < newLib->getSize(); ++i) {
			std::cout << x[i]->getTitle()<<std::endl;
		}
	}

	std::cout << "operazione di lettura completata";


	newLib->toJson(path_scrittura);
	
	std::cout << "operazione di scrittura completata";
}

	