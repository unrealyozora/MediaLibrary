#ifndef LIBRARY_H
#define LIBRARY_H
#include <AbstractItem.h>
#include <memory>
class Library {
private:
	std::vector<std::shared_ptr<AbstractItem>> media;
public:
	const unsigned int getSize() const;
	const bool is_empty() const;

	/*-------------------------------------------------------NUOVA AGGIUNTA-------------------------------------------------------*/
	// Metodo per aggiungere un oggetto alla libreria
	//void addItem(std::shared_ptr<AbstractItem> item);
	/*----------------------------------------------------------------------------------------------------------------------------*/

	//sezione gestione json/xml
	/*void toJson();
	void fromJson();
	void toXml();
	void fromXml();*/
};
#endif
