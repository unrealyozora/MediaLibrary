#include <qfile.h>
#include <QString>
#include <iostream>
#include <qxmlstream.h>
#include "xml_first_test.h"
#include "../library/Library.h"

void XmlTest::test() {
    QString path = "assets/provas.xml";
    QString write_path = "assets/scritturas.xml";
    Library* newLib = new Library();
    QFile file(path);
    try {
        newLib->fromXml(path);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    if (newLib->is_empty()) {
        std::cout << "La lista e' vuota";
    }
    else {
        auto x = newLib->getList();

        for (unsigned int i = 0; i < newLib->getSize(); ++i) {
            std::cout << x[i]->getTitle() << std::endl;
        }
        
    }

    try {
        newLib->toXml(write_path);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
