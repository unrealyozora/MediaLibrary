#include <qfile.h>
#include <qsdtring.h>
#include <iostream>
void test(){
    QString="assets/prova.xml";
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)){
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();
        while(!xmlReader.isEndDocument()){
            if (xmlReader.isStartElement()){
                QString title=xmlReader.name().toString();
                std::cout<<title.toStdString();
            }
        }
    }
}