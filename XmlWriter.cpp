#include "XmlWriter.h"
#include <qfile.h>
#include <qxmlstream.h>
void XmlWriter::writeXml(const QString& path, const QList<std::shared_ptr<AbstractItem>>& media) {
	QFile file(path);
	if (!file.open(QIODevice::WriteOnly)) {
		throw std::runtime_error(file.errorString().toStdString());
	}
	else {
		QXmlStreamWriter xmlWriter(&file);
	}
}
