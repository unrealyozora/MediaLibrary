#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QFile>
#include <QXmlStreamWriter>
#include "Library.h"

class XmlWriter {
public:
    static void writeXml(const QString& path, const QList<std::shared_ptr<AbstractItem>>& media);
};

#endif // XMLWRITER_H

