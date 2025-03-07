#include "XmlVisitor.h"
XmlVisitor::XmlVisitor(QXmlStreamWriter& writer) : xmlWriter(writer) {}

void XmlVisitor::visit(Album& album) {
    xmlWriter.writeStartElement("item");
    xmlWriter.writeAttribute("tipo", "Album");
    xmlWriter.writeTextElement("title", QString::fromStdString(album.getTitle()));
    xmlWriter.writeTextElement("year", QString::number(album.getYear()));
    xmlWriter.writeTextElement("description", QString::fromStdString(album.getDescription()));
    xmlWriter.writeTextElement("genre", QString::fromStdString(album.getGenre()));
    xmlWriter.writeTextElement("country", QString::fromStdString(album.getCountry()));
    xmlWriter.writeTextElement("image", QString::fromStdString(album.getImage()));
    xmlWriter.writeTextElement("author", QString::fromStdString(album.getAuthor()));
    xmlWriter.writeTextElement("songs", QString::number(album.getSongs()));
    xmlWriter.writeTextElement("length", QString::number(album.getLength()));
    xmlWriter.writeEndElement();
}

void XmlVisitor::visit(Books& book) {
    xmlWriter.writeStartElement("item");
    xmlWriter.writeAttribute("tipo", "Books");
    xmlWriter.writeTextElement("title", QString::fromStdString(book.getTitle()));
    xmlWriter.writeTextElement("year", QString::number(book.getYear()));
    xmlWriter.writeTextElement("description", QString::fromStdString(book.getDescription()));
    xmlWriter.writeTextElement("genre", QString::fromStdString(book.getGenre()));
    xmlWriter.writeTextElement("country", QString::fromStdString(book.getCountry()));
    xmlWriter.writeTextElement("image", QString::fromStdString(book.getImage()));
    xmlWriter.writeTextElement("author", QString::fromStdString(book.getAuthor()));
    xmlWriter.writeTextElement("pages", QString::number(book.getPages()));
    xmlWriter.writeTextElement("publ", QString::fromStdString(book.getPub()));
    xmlWriter.writeEndElement();
}

void XmlVisitor::visit(Comic& comic) {
    xmlWriter.writeStartElement("item");
    xmlWriter.writeAttribute("tipo", "Comic");
    xmlWriter.writeTextElement("title", QString::fromStdString(comic.getTitle()));
    xmlWriter.writeTextElement("year", QString::number(comic.getYear()));
    xmlWriter.writeTextElement("description", QString::fromStdString(comic.getDescription()));
    xmlWriter.writeTextElement("genre", QString::fromStdString(comic.getGenre()));
    xmlWriter.writeTextElement("country", QString::fromStdString(comic.getCountry()));
    xmlWriter.writeTextElement("image", QString::fromStdString(comic.getImage()));
    xmlWriter.writeTextElement("author", QString::fromStdString(comic.getAuthor()));
    xmlWriter.writeTextElement("chapters", QString::number(comic.getChapters()));
    xmlWriter.writeEndElement();
}

void XmlVisitor::visit(Movie& movie) {
    xmlWriter.writeStartElement("item");
    xmlWriter.writeAttribute("tipo", "Movie");
    xmlWriter.writeTextElement("title", QString::fromStdString(movie.getTitle()));
    xmlWriter.writeTextElement("year", QString::number(movie.getYear()));
    xmlWriter.writeTextElement("description", QString::fromStdString(movie.getDescription()));
    xmlWriter.writeTextElement("genre", QString::fromStdString(movie.getGenre()));
    xmlWriter.writeTextElement("country", QString::fromStdString(movie.getCountry()));
    xmlWriter.writeTextElement("image", QString::fromStdString(movie.getImage()));
    xmlWriter.writeTextElement("director", QString::fromStdString(movie.getDirector()));
    xmlWriter.writeTextElement("screenwriter", QString::fromStdString(movie.getScreenwriter()));
    xmlWriter.writeTextElement("length", QString::number(movie.getLength()));
    xmlWriter.writeTextElement("production_comp", QString::fromStdString(movie.getProd()));
    xmlWriter.writeEndElement();
}

void XmlVisitor::visit(Videogames& videogame) {
    xmlWriter.writeStartElement("item");
    xmlWriter.writeAttribute("tipo", "Videogame");
    xmlWriter.writeTextElement("title", QString::fromStdString(videogame.getTitle()));
    xmlWriter.writeTextElement("year", QString::number(videogame.getYear()));
    xmlWriter.writeTextElement("description", QString::fromStdString(videogame.getDescription()));
    xmlWriter.writeTextElement("genre", QString::fromStdString(videogame.getGenre()));
    xmlWriter.writeTextElement("country", QString::fromStdString(videogame.getCountry()));
    xmlWriter.writeTextElement("image", QString::fromStdString(videogame.getImage()));
    xmlWriter.writeTextElement("developer", QString::fromStdString(videogame.getDeveloper()));
    xmlWriter.writeTextElement("multiplayer", videogame.getMultiplayer() ? "true" : "false");
    xmlWriter.writeEndElement();
}
