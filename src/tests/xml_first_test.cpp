#include <qfile.h>
#include <QString>
#include <iostream>
#include <qxmlstream.h>
#include "xml_first_test.h"
#include "../library/Library.h"
#include "../items/Videogames.h"

void XmlTest::test() {
    QString path = "assets/prova.xml";
    QString write_path = "assets/scrittura.xml";
    Library* newLib = new Library();
    QFile file(path);
    try {
        newLib->fromXml(path);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "finito xml" << std::endl;
    if (newLib->is_empty()) {
        std::cout << " La lista e' vuota, ziopovero ";
    }
    else {
        auto x = newLib->getList();

        std::cout<<dynamic_cast<Videogames*>(x[2].get())->getMultiplayer();
        
    }

    try {
        newLib->toXml(write_path);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
