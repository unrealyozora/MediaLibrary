#ifndef XML_WRITER_H
#define XML_WRITER_H

#include <QFile>
#include <QXmlStreamWriter>
#include "../library/Library.h"

class XmlWriter {
public:
    static void writeXml(const QString& path, const QList<std::shared_ptr<AbstractItem>>& media);
};

#endif // XMLWRITER_H

