#include "Library.h"
#include <qfile.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <JsonReader.h>
#include <jsonVisitor.h>

const unsigned int Library::getSize() const {
	return media.size();
}

const bool Library::is_empty() const {
	return media.empty();
}

QList<std::shared_ptr<AbstractItem>> Library::getList() const {
	return media;
}

void Library::addItem(std::shared_ptr<AbstractItem> item) {
	media.append(item);
}

void Library::removeItem(const std::string& title, unsigned int year) {
	for (int x = 0; x < media.size(); x++) {
		if (media[x]->getTitle() == title && media[x]->getYear() == year) {
			media.removeAt(x);
		}
	}
}

void Library::fromJson(const QString& path) {
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly)) {
		throw QString("Error when opening file");
	}else {
		QByteArray docData = file.readAll();
		file.close();
		QJsonDocument doc = QJsonDocument::fromJson(docData);
		QJsonArray array = doc.array();
		for (const auto& item : array) {
			QJsonObject itemObject = item.toObject();
			QString category = itemObject["tipo"].toString();
			std::shared_ptr<AbstractItem> newItem;
			if (category == "Movie") {
				newItem = JsonReader::readMovie(itemObject);
			}
			else if (category == "Album") {
				newItem = JsonReader::readAlbum(itemObject);
			}
			else if (category == "Videogame") {
				newItem = JsonReader::readVideogame(itemObject);
			}
			else if (category == "Comic") {
				newItem = JsonReader::readComic(itemObject);
			}
			else if (category == "Books") {
				newItem = JsonReader::readBooks(itemObject);
			}
			media.append(newItem);
		}
	}
}

void Library::toJson(const QString &path) const {
	jsonVisitor json_visitor;
	QFile file(path);
	//aggiungere gestione libreria vuota
	if (!file.open(QIODevice::WriteOnly)){
		throw QString ("Error when opening file");
	}else{
		for (auto& x:this->getList()){
			x->accept(json_visitor);
		}
		//scrittura su documento
		QJsonDocument doc (json_visitor.getArray());
		file.write(doc.toJson());
		file.close();
	}
}
