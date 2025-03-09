#include <qfile.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <iostream>
#include <QXmlStreamReader>
#include <QDebug>
#include "Library.h"
#include "../jsonXml/JsonReader.h"
#include "../jsonXml/JsonWriter.h"
#include "../jsonXml/XmlParser.h"
#include "../jsonXml/XmlWriter.h"

Library* Library::instance = nullptr;
Library* Library::getInstance() {
	if (instance == nullptr) {
		instance = new Library();
	}
	return instance;
	
}

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
	media.clear();
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly)) {
		throw std::runtime_error(file.errorString().toStdString());
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
	emit updateList(media);
}

void Library::toJson(const QString& path) const {
	try {
		JsonWriter::writeJson(path, this->getList());
	}
	catch (QString& s){
		std::cout << s.toStdString() << std::endl; //libreria vuota
	}
	catch (const std::runtime_error& e) {	//errore nel file
		std::cerr << e.what() << std::endl;
	}
	
}


void Library::fromXml(const QString& path) {
	media.clear();
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly)) {
		throw std::runtime_error(file.errorString().toStdString());
	}

	QXmlStreamReader xmlReader(&file);

	while (!xmlReader.atEnd() && !xmlReader.hasError()) {
		QXmlStreamReader::TokenType token = xmlReader.readNext();

		if (token == QXmlStreamReader::StartElement && xmlReader.name() == "item") {
			QXmlStreamAttributes attributes = xmlReader.attributes();
			if (attributes.hasAttribute("tipo")) {
				QString category = attributes.value("tipo").toString();
				std::shared_ptr<AbstractItem> newItem;
				if (category == "Movie") {
					newItem = XmlParser::parseMovie(xmlReader);
				}
				else if (category == "Album") {
					newItem = XmlParser::parseAlbum(xmlReader);
				}
				else if (category == "Videogame") {
					newItem = XmlParser::parseVideogame(xmlReader);
				}
				else if (category == "Comic") {
					newItem = XmlParser::parseComic(xmlReader);
				}
				else if (category == "Books") {
					newItem = XmlParser::parseBook(xmlReader);
				}

				if (newItem) {
					media.append(newItem);
				}
			}
		}
	}

	if (xmlReader.hasError()) {
		throw std::runtime_error(xmlReader.errorString().toStdString());
	}

	file.close();
	emit updateList(media);
}

void Library::toXml(const QString& path) const {
	try {
		XmlWriter::writeXml(path, media);
	}
	catch (QString& s) {
		std::cout << s.toStdString() << std::endl; //libreria vuota
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;	//errore nel file
	}
}

