#include "ItemDetailVisitor.h"  
#include <QString>  
#include <QLayout>  
#include <QLineEdit>  
#include <QFont>  
#include <QLabel>  
#include <QPixmap>
#include <QFormLayout>

void ItemDetailVisitor::visit(Album& album) {
    // Rimuove layout precedente se esiste
    if (widget->layout() != nullptr) {
        QLayoutItem* item;
        while ((item = widget->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete widget->layout();
    }

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();
    QGridLayout* infoLayout = new QGridLayout();

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(album.getImage()));
    int imageHeight = widget->parentWidget()->height() - 20;
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight);
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

    // *** TITOLO ***
    QLabel* titleLabel = new QLabel(QString::fromStdString(album.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    infoLayout->addWidget(titleLabel, 0, 0, 1, 2, Qt::AlignCenter);

    // ** Spazio dopo il titolo **
    infoLayout->setRowMinimumHeight(1, 15);

    // *** INFO ***
    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(album.getAuthor()));
    infoLayout->addWidget(authorLabel, 2, 0);
    infoLayout->addWidget(authorEdit, 3, 0, 1, 2); // Occupa due colonne per allineamento migliore

    // Spazio tra le sezioni
    infoLayout->setRowMinimumHeight(4, 10);

    QLabel* songsLabel = new QLabel("Songs:");
    QLineEdit* songsEdit = new QLineEdit(QString::number(album.getSongs()));
    infoLayout->addWidget(songsLabel, 5, 0);
    infoLayout->addWidget(songsEdit, 6, 0, 1, 2);

    infoLayout->setRowMinimumHeight(7, 10);

    QLabel* lengthLabel = new QLabel("Length:");
    QLineEdit* lengthEdit = new QLineEdit(QString::number(album.getLength()));
    infoLayout->addWidget(lengthLabel, 8, 0);
    infoLayout->addWidget(lengthEdit, 9, 0, 1, 2);

    // Spazio per separare il bottone
    infoLayout->setRowMinimumHeight(10, 30);

    // *** BACK BUTTON ***
    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedWidth(150); // Rende il bottone più visibile
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
    infoLayout->addWidget(backButton, 11, 0, 1, 2, Qt::AlignCenter);

    // *** ASSEMBLAGGIO LAYOUT ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addLayout(infoLayout);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

    widget->setLayout(mainLayout);
}


void ItemDetailVisitor::visit(Books& book) {
	if (widget->layout() != nullptr) {
		QLayoutItem* item;
		while ((item = widget->layout()->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete widget->layout();
	}

   QHBoxLayout* mainLayout = new QHBoxLayout();
   QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(book.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
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

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back");
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}  

void ItemDetailVisitor::visit(Comic& comic) {
	if (widget->layout() != nullptr) {
		QLayoutItem* item;
		while ((item = widget->layout()->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete widget->layout();
	}

	QHBoxLayout* mainLayout = new QHBoxLayout();
	QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(comic.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
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

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back");
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}  

void ItemDetailVisitor::visit(Movie& movie) {
	if (widget->layout() != nullptr) {
		QLayoutItem* item;
		while ((item = widget->layout()->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete widget->layout();
	}

	QHBoxLayout* mainLayout = new QHBoxLayout();
	QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(movie.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
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

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back");
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}  

void ItemDetailVisitor::visit(Videogames& videogame) {
	if (widget->layout() != nullptr) {
		QLayoutItem* item;
		while ((item = widget->layout()->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete widget->layout();
	}

	QHBoxLayout* mainLayout = new QHBoxLayout();
	QVBoxLayout* infoLayout = new QVBoxLayout();

   QLabel* imageLabel = new QLabel();
   QPixmap pixmap(QString::fromStdString(videogame.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
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

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back");
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}
