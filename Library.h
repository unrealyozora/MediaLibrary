#ifndef LIBRARY_H
#define LIBRARY_H
#include <AbstractItem.h>
#include <qlist.h>
#include <memory>
class Library {
private:
	QList<std::shared_ptr<AbstractItem>> media;
public:
	const unsigned int getSize() const;
	const bool is_empty() const;
	QList<std::shared_ptr<AbstractItem>> getList() const;

	//Metodi per aggiungere e rimuovere un oggetto alla libreria
	void addItem(std::shared_ptr<AbstractItem> item);
	void removeItem(const std::string& title, unsigned int year); //il metodo removeItem richiede il titolo e l'anno, in modo da non creare eventuali casi di omonimia
	
	void fromJson(const QString& path);
	//sezione gestione json/xml
	/*void toJson();
	
	void toXml();
	void fromXml();*/
};
#endif
