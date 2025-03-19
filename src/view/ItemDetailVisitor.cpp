#include "ItemDetailVisitor.h"
#include <QString>
#include <QLayout>
#include <QLineEdit>

void ItemDetailVisitor::visit(Album& album) {

    QVBoxLayout* layout = new QVBoxLayout();

    QLabel* label = new QLabel(QString::fromStdString(album.getTitle()));
    layout->addWidget(label);

    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(album.getAuthor()));
    layout->addWidget(authorLabel);
    layout->addWidget(authorEdit);

    QLabel* songsLabel = new QLabel("Songs:");
    QLineEdit* songsEdit = new QLineEdit(QString::number(album.getSongs()));
    layout->addWidget(songsLabel);
    layout->addWidget(songsEdit);

    QLabel* lengthLabel = new QLabel("Length:");
    QLineEdit* lengthEdit = new QLineEdit(QString::number(album.getLength()));
    layout->addWidget(lengthLabel);
    layout->addWidget(lengthEdit);

    widget->setLayout(layout);
}

void ItemDetailVisitor::visit(Books& book) {

    QVBoxLayout* layout = new QVBoxLayout();

    QLabel* label = new QLabel(QString::fromStdString(book.getTitle()));
    layout->addWidget(label);

    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(book.getAuthor()));
    layout->addWidget(authorLabel);
    layout->addWidget(authorEdit);

    QLabel* pagesLabel = new QLabel("Pages:");
    QLineEdit* pagesEdit = new QLineEdit(QString::number(book.getPages()));
    layout->addWidget(pagesLabel);
    layout->addWidget(pagesEdit);

    QLabel* publHouseLabel = new QLabel("Publishing House:");
    QLineEdit* publHouseEdit = new QLineEdit(QString::fromStdString(book.getPub()));
    layout->addWidget(publHouseLabel);
    layout->addWidget(publHouseEdit);

    widget->setLayout(layout);
}

void ItemDetailVisitor::visit(Comic& comic) {

    QVBoxLayout* layout = new QVBoxLayout();

    QLabel* label = new QLabel(QString::fromStdString(comic.getTitle()));
    layout->addWidget(label);

    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(comic.getAuthor()));
    layout->addWidget(authorLabel);
    layout->addWidget(authorEdit);

    QLabel* chaptersLabel = new QLabel("Chapters:");
    QLineEdit* chaptersEdit = new QLineEdit(QString::number(comic.getChapters()));
    layout->addWidget(chaptersLabel);
    layout->addWidget(chaptersEdit);

    widget->setLayout(layout);
}

void ItemDetailVisitor::visit(Movie& movie) {

    QVBoxLayout* layout = new QVBoxLayout();

    QLabel* label = new QLabel(QString::fromStdString(movie.getTitle()));
    layout->addWidget(label);

    QLabel* directorLabel = new QLabel("Director:");
    QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(movie.getDirector()));
    layout->addWidget(directorLabel);
    layout->addWidget(directorEdit);

    QLabel* screenwriterLabel = new QLabel("Screenwriter:");
    QLineEdit* screenwriterEdit = new QLineEdit(QString::fromStdString(movie.getScreenwriter()));
    layout->addWidget(screenwriterLabel);
    layout->addWidget(screenwriterEdit);

    QLabel* lengthLabel = new QLabel("Length:");
    QLineEdit* lengthEdit = new QLineEdit(QString::number(movie.getLength()));
    layout->addWidget(lengthLabel);
    layout->addWidget(lengthEdit);

    QLabel* prodCompanyLabel = new QLabel("Production Company:");
    QLineEdit* prodCompanyEdit = new QLineEdit(QString::fromStdString(movie.getProd()));
    layout->addWidget(prodCompanyLabel);
    layout->addWidget(prodCompanyEdit);

    widget->setLayout(layout);
}

void ItemDetailVisitor::visit(Videogames& videogame) {

    QVBoxLayout* layout = new QVBoxLayout();

    QLabel* label = new QLabel(QString::fromStdString(videogame.getTitle()));
    layout->addWidget(label);

    QLabel* developerLabel = new QLabel("Developer:");
    QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));
    layout->addWidget(developerLabel);
    layout->addWidget(developerEdit);

    QLabel* multiplayerLabel = new QLabel("Multiplayer:");
    QLineEdit* multiplayerEdit = new QLineEdit(videogame.getMultiplayer() ? "Yes" : "No");
    layout->addWidget(multiplayerLabel);
    layout->addWidget(multiplayerEdit);

    widget->setLayout(layout);
}
