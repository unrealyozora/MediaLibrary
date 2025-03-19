#include "ItemDetailVisitor.h"  
#include <QString>  
#include <QLayout>  
#include <QLineEdit>  
#include <QFont>  
#include <QLabel>  
#include <QPixmap>  

void ItemDetailVisitor::visit(Album& album) {  

   QHBoxLayout* mainLayout = new QHBoxLayout();  
   QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();  
   QPixmap pixmap(QString::fromStdString(album.getImage()));  
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, widget->parentWidget()->height(), Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, widget->parentWidget()->height()); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(album.getTitle()));  
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* authorLabel = new QLabel("Author:");  
   QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(album.getAuthor()));  
   infoLayout->addWidget(authorLabel);  
   infoLayout->addWidget(authorEdit);  

   QLabel* songsLabel = new QLabel("Songs:");  
   QLineEdit* songsEdit = new QLineEdit(QString::number(album.getSongs()));  
   infoLayout->addWidget(songsLabel);  
   infoLayout->addWidget(songsEdit);  

   QLabel* lengthLabel = new QLabel("Length:");  
   QLineEdit* lengthEdit = new QLineEdit(QString::number(album.getLength()));  
   infoLayout->addWidget(lengthLabel);  
   infoLayout->addWidget(lengthEdit);  

   infoLayout->setSpacing(0); // Set the spacing between components  

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}

void ItemDetailVisitor::visit(Books& book) {  

   QHBoxLayout* mainLayout = new QHBoxLayout();
   QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(book.getImage()));
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, widget->parentWidget()->height(), Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, widget->parentWidget()->height()); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image   

   QLabel* label = new QLabel(QString::fromStdString(book.getTitle()));  
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* authorLabel = new QLabel("Author:");  
   QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(book.getAuthor()));  
   infoLayout->addWidget(authorLabel);  
   infoLayout->addWidget(authorEdit);  

   QLabel* pagesLabel = new QLabel("Pages:");  
   QLineEdit* pagesEdit = new QLineEdit(QString::number(book.getPages()));  
   infoLayout->addWidget(pagesLabel);  
   infoLayout->addWidget(pagesEdit);  

   QLabel* publHouseLabel = new QLabel("Publishing House:");  
   QLineEdit* publHouseEdit = new QLineEdit(QString::fromStdString(book.getPub()));  
   infoLayout->addWidget(publHouseLabel);  
   infoLayout->addWidget(publHouseEdit);  

   infoLayout->setSpacing(10); // Set the spacing between components  

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}  

void ItemDetailVisitor::visit(Comic& comic) {  

	QHBoxLayout* mainLayout = new QHBoxLayout();
	QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(comic.getImage()));
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, widget->parentWidget()->height(), Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, widget->parentWidget()->height()); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image   

   QLabel* label = new QLabel(QString::fromStdString(comic.getTitle()));  
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* authorLabel = new QLabel("Author:");  
   QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(comic.getAuthor()));  
   infoLayout->addWidget(authorLabel);  
   infoLayout->addWidget(authorEdit);  

   QLabel* chaptersLabel = new QLabel("Chapters:");  
   QLineEdit* chaptersEdit = new QLineEdit(QString::number(comic.getChapters()));  
   infoLayout->addWidget(chaptersLabel);  
   infoLayout->addWidget(chaptersEdit);  

   infoLayout->setSpacing(10); // Set the spacing between components  

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}  

void ItemDetailVisitor::visit(Movie& movie) {  

	QHBoxLayout* mainLayout = new QHBoxLayout();
	QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(movie.getImage()));
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, widget->parentWidget()->height(), Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, widget->parentWidget()->height()); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(movie.getTitle()));  
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* directorLabel = new QLabel("Director:");  
   QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(movie.getDirector()));  
   infoLayout->addWidget(directorLabel);  
   infoLayout->addWidget(directorEdit);  

   QLabel* screenwriterLabel = new QLabel("Screenwriter:");  
   QLineEdit* screenwriterEdit = new QLineEdit(QString::fromStdString(movie.getScreenwriter()));  
   infoLayout->addWidget(screenwriterLabel);  
   infoLayout->addWidget(screenwriterEdit);  

   QLabel* lengthLabel = new QLabel("Length:");  
   QLineEdit* lengthEdit = new QLineEdit(QString::number(movie.getLength()));  
   infoLayout->addWidget(lengthLabel);  
   infoLayout->addWidget(lengthEdit);  

   QLabel* prodCompanyLabel = new QLabel("Production Company:");  
   QLineEdit* prodCompanyEdit = new QLineEdit(QString::fromStdString(movie.getProd()));  
   infoLayout->addWidget(prodCompanyLabel);  
   infoLayout->addWidget(prodCompanyEdit);  

   infoLayout->setSpacing(10); // Set the spacing between components  

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}  

void ItemDetailVisitor::visit(Videogames& videogame) {  

	QHBoxLayout* mainLayout = new QHBoxLayout();
	QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(videogame.getImage()));
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, widget->parentWidget()->height(), Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, widget->parentWidget()->height()); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(videogame.getTitle()));  
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* developerLabel = new QLabel("Developer:");  
   QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));  
   infoLayout->addWidget(developerLabel);  
   infoLayout->addWidget(developerEdit);  

   QLabel* multiplayerLabel = new QLabel("Multiplayer:");  
   QLineEdit* multiplayerEdit = new QLineEdit(videogame.getMultiplayer() ? "Yes" : "No");  
   infoLayout->addWidget(multiplayerLabel);  
   infoLayout->addWidget(multiplayerEdit);  

   infoLayout->setSpacing(10); // Set the spacing between components  

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}
