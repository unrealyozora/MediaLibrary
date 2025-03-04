#include <Library.h>
#include <QString>
#include <iostream>
static void test() {
	QString path = "C:\\Users\\tomma\\Dev\\MediaLibrary\\assets\\prova.json";
	Library* newLib = new Library();
	try {
		newLib->fromJson(path);
	}
	catch (QString s) { std::cout << s; 
	}

	if (newLib->is_empty()) {
		std::cout << "La lista � vuota, ziopovero";
	} else {
		auto x = newLib->getList();
		for (int i = 0; i < newLib->getSize(); ++i) {
			std::cout << x[i]->getTitle()<<std::endl;
		}
	}
}

	