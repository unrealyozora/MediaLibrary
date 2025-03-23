#include "XmlWriter.h"
#include "XmlVisitor.h"

void XmlWriter::writeXml(const QString& path, const QList<std::shared_ptr<AbstractItem>>& media) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        throw std::runtime_error(file.errorString().toStdString());
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("items");

    XmlVisitor visitor(xmlWriter);
    for (const auto& item : media) {
        item->accept(visitor);
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}
