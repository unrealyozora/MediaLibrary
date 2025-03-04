#include <Library.h>
#include <QString>
#include <iostream>
static void test() {
	QString path_lettura = "C:\\Users\\tomma\\Dev\\MediaLibrary\\assets\\prova.json";
	QString path_scrittura = "C:\\Users\\tomma\\Dev\\MediaLibrary\\assets\\prova_scrittura.json";
	Library* newLib = new Library();
	try {
		newLib->fromJson(path_lettura);
	}
	catch (QString s) { std::cout << s.toStdString(); 
	}

	if (newLib->is_empty()) {
		std::cout << "La lista � vuota, ziopovero";
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
	catch (QString s) { std::cout << s.toStdString(); 
	}
	std::cout << "operazione di scrittura completata";
}

	