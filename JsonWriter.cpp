#include "JsonWriter.h"
#include <qfile.h>
#include <qjsondocument.h>

void JsonWriter::writeJson(const QString& path, const QList<std::shared_ptr<AbstractItem>>& media) {
    JsonVisitor visitor;
    QFile file(path);
        if (!file.open(QIODevice::WriteOnly)) {
            throw std::runtime_error(file.errorString().toStdString());
        }

    for (const auto& item : media) {
        item->accept(visitor);
    }

    QJsonDocument jsonDoc(visitor.getArray());

    file.write(jsonDoc.toJson());
    file.close();
}
