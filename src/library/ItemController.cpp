#include "ItemController.h"
#include "ItemController.h"

ItemController::ItemController(QObject *parent):QObject(parent){}

Album* CreateAlbum(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _author, unsigned int _songs, unsigned int _length){
    return new Album(_title, year, _description, _genre, _country, _image, _author, _songs, _length);
}
static void passItem(AbstractItem* item){
    Library::getInstance()->addItem(item);
}