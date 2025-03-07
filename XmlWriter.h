#ifndef XML_WRITER_H
#define XML_WRITER_H
#include <QFile>
#include <memory>
#include <AbstractItem.h>
#include "XmlVisitor.h" // Includiamo il Visitor

class XmlWriter {
public:
    static void writeXml(const QString& path, const QList<std::shared_ptr<AbstractItem>>& media);
};
#endif
