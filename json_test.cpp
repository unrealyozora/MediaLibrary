#include <Library.h>
#include <QString>
#include <iostream>
static void test() {
	QString path_lettura = "C:\\Users\\Dennis\\Desktop\\i4file\\prova.json";
	QString path_scrittura = "C:\\Users\\Dennis\\Desktop\\i4file\\prova_scrittura.json";
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
		for (int i = 0; i < newLib->getSize(); ++i) {
			std::cout << x[i]->getTitle()<<std::endl;
		}
	}

	std::cout << "operazione di lettura completata";

	try {
		newLib->toJson(path_scrittura);
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "operazione di scrittura completata";
}

	