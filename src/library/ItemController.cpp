#include "ItemController.h"
#include "../library/Library.h"
#include "../items/AbstractItem.h"
#include "../items/album.h"
#include "../items/Books.h"
#include "../items/Comic.h"
#include "../items/movie.h"
#include "../items/Videogames.h"


#include <iostream>
#include <QDebug>//debug only
ItemController::ItemController(QObject *parent):QObject(parent){}

void ItemController::passAlbum(const std::string& _title, unsigned int _year, const std::string& _description, 
                               const std::string& _genre, const std::string& _country, const std::string& _image, 
                               const std::string& _author, unsigned int _songs, unsigned int _length){   

    qDebug()<<"pass completed";
    std::shared_ptr<AbstractItem> album =std::make_shared<Album>(_title, _year, _description, _genre, _country, _image, _author, _songs, _length);
    Library::getInstance()->addItem(album);
    
}

void ItemController::passBook(const std::string& _title, unsigned int _year, const std::string& _description, 
                              const std::string& _genre, const std::string& _country, const std::string& _image, 
                              const std::string& _author, unsigned int _pages, const std::string& _publ_house){
    std::shared_ptr<AbstractItem> book = std::make_shared<Books>(_title, _year, _description, _genre, _country, _image, _author, _pages, _publ_house);
    Library::getInstance()->addItem(book);
    std::cout << "passBook" << std::endl;
}

void ItemController::passComic(const std::string& _title, unsigned int _year, const std::string& _description, 
                               const std::string& _genre, const std::string& _country, const std::string& _image, 
                               const std::string& _author, unsigned int _chapters){
    std::shared_ptr<AbstractItem> comic = std::make_shared<Comic>(_title, _year, _description, _genre, _country, _image, _author, _chapters);
    Library::getInstance()->addItem(comic);
    std::cout << "passComic" << std::endl;
}

void ItemController::passMovie(const std::string& _title, unsigned int _year, const std::string& _description, 
                               const std::string& _genre, const std::string& _country, const std::string& _image, 
                               const std::string& _director, const std::string& _screenwriter, unsigned int _length, const std::string& _production_company){
    std::shared_ptr<AbstractItem> movie = std::make_shared<Movie>(_title, _year, _description, _genre, _country, _image, _director, _screenwriter, _length, _production_company);
    Library::getInstance()->addItem(movie);
    std::cout << "passMovie" << std::endl;
}

void ItemController::passVideogame(const std::string& _title, unsigned int _year, const std::string& _description,
                                   const std::string& _genre, const std::string& _country, const std::string& _image, 
                                   const std::string& _developer, bool _multiplayer){
    std::shared_ptr<AbstractItem> videogame = std::make_shared<Videogames>(_title, _year, _description, _genre, _country, _image, _developer, _multiplayer);
    Library::getInstance()->addItem(videogame);
    std::cout << "passVideogame" << std::endl;
}


