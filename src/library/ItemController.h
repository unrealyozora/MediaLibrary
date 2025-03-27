#ifndef LIBRARY_ITEM_CONTROLLER_H
#define LIBRARY_ITEM_CONTROLLER_H
#include <memory>
#include <QObject>
class ItemController:public QObject{
Q_OBJECT
public:
    explicit ItemController(QObject* parent=nullptr);
    static void passAlbum(const std::string& _title, unsigned int _year, const std::string& _description, 
                          const std::string& _genre, const std::string& _country, const std::string& _image, 
                          const std::string& _author, unsigned int _songs, unsigned int _length);
    static void passBook(const std::string& _title, unsigned int _year, const std::string& _description,
                         const std::string& _genre, const std::string& _country, const std::string& _image,
                         const std::string& _author, unsigned int _pages, const std::string& _publ_house);
    static void passComic(const std::string& _title, unsigned int _year, const std::string& _description, 
                          const std::string& _genre, const std::string& _country, const std::string& _image, 
                          const std::string& _author, unsigned int _chapters);
    static void passMovie(const std::string& _title, unsigned int _year, const std::string& _description,
                          const std::string& _genre, const std::string& _country, const std::string& _image,
                          const std::string& _director, const std::string& _screenwriter, unsigned int _length,
                          const std::string& _production_company);
    static void passVideogame(const std::string& _title, unsigned int _year, const std::string& _description,
                              const std::string& _genre, const std::string& _country, const std::string& _image,
                              const std::string& _developer, bool _multiplayer);
};
#endif