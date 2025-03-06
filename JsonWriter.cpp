#include "JsonWriter.h"
#include <qfile.h>
#include <qjsondocument.h>
void JsonWriter::writeJson(const QList<std::shared_ptr<AbstractItem>>& items, const QString& path) {
    JsonVisitor json_visitor;
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        throw std::runtime_error(file.errorString().toStdString());
    }
    else {
        for (auto& x : items) {
            x->accept(json_visitor);
        }
        QJsonDocument doc(json_visitor.getArray());
        file.write(doc.toJson());
        file.close();
    }
}
