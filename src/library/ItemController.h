#ifndef LIBRARY_ITEM_CONTROLLER_H
#define LIBRARY_ITEM_CONTROLLER_H
#include <QObject>
#include "../library/Library.h"
#include "../items/AbstractItem.h"
#include "../items/album.h"
class ItemController:public QObject{
Q_OBJECT
public:
    explicit ItemController(QObject* parent=nullptr);
    Album* CreateAlbum(const std::string& _title, unsigned int _year, const std::string& _description, const std::string& _genre, const std::string& _country, const std::string& _image, const std::string& _author, unsigned int _songs, unsigned int _length);
    static void passItem(AbstractItem* item);
signals:
    void itemCreated(AbstractItem* item);
};
#endif