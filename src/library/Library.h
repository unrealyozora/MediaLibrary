#ifndef LIBRARY_H
#define LIBRARY_H
#include <memory>
#include 
"../items/AbstractItem.h"
#include <QList>
#include <QObject>
class Library: public QObject {
	Q_OBJECT
private:
	static Library* instance;
	Library() {};
	Library(const Library&) = delete;
	Library& operator=(const Library&) = delete;
	QList<std::shared_ptr<AbstractItem>> media;
	std::string filePath;
public:
	static Library* getInstance();
	const unsigned int getSize() const;
	const bool is_empty() const;
	QList<std::shared_ptr<AbstractItem>> getList() const;

	//Metodi per aggiungere e rimuovere un oggetto alla libreria
	void addItem(std::shared_ptr<AbstractItem> item);
	void removeItem(const std::string& title, unsigned int year); //il metodo removeItem richiede il titolo e l'anno, in modo da non creare eventuali casi di omonimia
	void updateItem(const AbstractItem& item);
	
	//sezione gestione json
	void fromJson(const QString& path);
	void toJson(const QString& path) const;
	
	//sezione gestione xml
	void fromXml(const QString& path);
	void toXml(const QString& path) const;

signals:
	void updateList(const QList<std::shared_ptr<AbstractItem>>& newList);  // Notifica quando la lista cambia
};
#endif
