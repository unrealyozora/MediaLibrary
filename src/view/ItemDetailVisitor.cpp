#include "ItemDetailVisitor.h"  
#include <QString>  
#include <QLayout>  
#include <QLineEdit>  
#include <QFont>  
#include <QLabel>  
#include <QPixmap>
#include <QFormLayout>

void ItemDetailVisitor::visit(Album& album) {
    QVBoxLayout* mainLayout = new QVBoxLayout(widget);
    QHBoxLayout* topLayout = new QHBoxLayout(widget);
    QGridLayout* infoLayout = new QGridLayout(widget);
    }
    }
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();
    QGridLayout* infoLayout = new QGridLayout();

    QHBoxLayout* topLayout = new QHBoxLayout();
    QGridLayout* infoLayout = new QGridLayout();

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel(widget);
    QPixmap pixmap(QString::fromStdString(album.getImage()));
    int imageHeight = widget->parentWidget()->height();
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(20, 0, 40, 0); // Margini laterali

    QLabel* titleLabel = new QLabel(QString::fromStdString(album.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(album.getYear()));
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(album.getDescription()));
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(album.getGenre()));
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(album.getCountry()));
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* authorLabel = new QLabel("Author:");
    infoLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO (Label accanto alla LineEdit senza spazio extra) ***
    QLabel* authorLabel = new QLabel("Author:");
    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* songsLabel = new QLabel("Songs:");
    authorEdit->setReadOnly(true);
    infoLayout->addWidget(authorLabel);
    infoLayout->addWidget(authorEdit);

    QLabel* songsLabel = new QLabel("Songs:");
    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* lengthLabel = new QLabel("Length:");
    songsEdit->setReadOnly(true);
    infoLayout->addWidget(songsLabel);
    infoLayout->addWidget(songsEdit);

    QLabel* lengthLabel = new QLabel("Length:");
    QLineEdit* lengthEdit = new QLineEdit(QString::number(album.getLength()));
    lengthEdit->setReadOnly(true);
    infoLayout->addWidget(lengthLabel);
    infoLayout->addWidget(lengthEdit);
    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    //QObject::connect(modifyButton, &QPushButton::clicked, widget, &ItemDetailsWidget::modifyItem);

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);

    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    // *** BACK BUTTON ***
    QPushButton* backButton = new QPushButton("Back");
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(infoWidget, 1);
    rightLayout->addWidget(buttonWidget, 0);
    rightLayout->setSpacing(0);
    // *** ASSEMBLAGGIO LAYOUT ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addLayout(infoLayout);
    rightLayout->addStretch();  // Spinge il bottone in basso
    rightLayout->addLayout(buttonLayout);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

    //widget->getLayout()->addLayout(mainLayout);
	if (widget->layout() != nullptr) {
		QLayoutItem* item;
		while ((item = widget->layout()->takeAt(0)) != nullptr) {
			delete item->widget();
			delete item;
		}
		delete widget->layout();
	}
			delete item->widget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();
		delete widget->layout();
    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(book.getImage()));
    int imageHeight = widget->parentWidget()->height();
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);
   QPixmap pixmap(QString::fromStdString(book.getImage()));
    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(40, 0, 40, 0); // Margini laterali
   QLabel* label = new QLabel(QString::fromStdString(book.getTitle()));  
    QLabel* titleLabel = new QLabel(QString::fromStdString(book.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    infoLayout->addSpacing(65); // Spazio prima del titolo
    infoLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(book.getYear()));
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(book.getDescription()));
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(book.getGenre()));
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(book.getCountry()));
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(book.getAuthor()));
    authorEdit->setReadOnly(true);
    infoLayout->addWidget(authorLabel);
    infoLayout->addWidget(authorEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* pagesLabel = new QLabel("Pages:");
    QLineEdit* pagesEdit = new QLineEdit(QString::number(book.getPages()));
    pagesEdit->setReadOnly(true);
    infoLayout->addWidget(pagesLabel);
    infoLayout->addWidget(pagesEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* publHouseLabel = new QLabel("Publishing House:");
    QLineEdit* publHouseEdit = new QLineEdit(QString::fromStdString(book.getPub()));
    publHouseEdit->setReadOnly(true);
    infoLayout->addWidget(publHouseLabel);
    infoLayout->addWidget(publHouseEdit);

   QLabel* publHouseLabel = new QLabel("Publishing House:");  
   QLineEdit* publHouseEdit = new QLineEdit(QString::fromStdString(book.getPub()));  
   infoLayout->addWidget(publHouseLabel);  
   infoLayout->addWidget(publHouseEdit);  
    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    //QObject::connect(modifyButton, &QPushButton::clicked, widget, &ItemDetailsWidget::modifyItem);

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);

    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(infoWidget, 1);
    rightLayout->addWidget(buttonWidget, 0);
    rightLayout->setSpacing(0);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

    widget->setLayout(mainLayout);
}
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(comic.getImage()));
    int imageHeight = widget->parentWidget()->height();
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(40, 0, 40, 0); // Margini laterali

    QLabel* titleLabel = new QLabel(QString::fromStdString(comic.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    infoLayout->addSpacing(65); // Spazio prima del titolo
    infoLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(comic.getYear()));
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(comic.getDescription()));
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(comic.getGenre()));
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(comic.getCountry()));
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);
   QPixmap pixmap(QString::fromStdString(comic.getImage()));
    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit
   QLabel* label = new QLabel(QString::fromStdString(comic.getTitle()));  
   QLabel* authorLabel = new QLabel("Author:");  
   QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(comic.getAuthor()));
   authorEdit->setReadOnly(true);
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* authorLabel = new QLabel("Author:");  
   QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(comic.getAuthor()));  
   infoLayout->addWidget(authorLabel);  
   QLineEdit* chaptersEdit = new QLineEdit(QString::number(comic.getChapters()));
   chaptersEdit->setReadOnly(true);

   infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

   QLabel* chaptersLabel = new QLabel("Chapters:");  
   QLineEdit* chaptersEdit = new QLineEdit(QString::number(comic.getChapters()));  
   infoLayout->addWidget(chaptersLabel);  
   infoLayout->addWidget(chaptersEdit);  

   infoLayout->addStretch(); // Spinge tutto in alto
   infoWidget->setLayout(infoLayout);
   infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

   // *** WIDGET CONTENITORE PULSANTE ***
   QWidget* buttonWidget = new QWidget();
   QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

   QPushButton* modifyButton = new QPushButton("Modify");
   modifyButton->setFixedSize(150, 40);
   //QObject::connect(modifyButton, &QPushButton::clicked, widget, &ItemDetailsWidget::modifyItem);
   QPushButton* backButton = new QPushButton("Back");
   backButton->setFixedSize(150, 40);
   QPushButton* saveButton = new QPushButton("Save");
   saveButton->setFixedSize(150, 40);
   saveButton->setEnabled(false);

   QPushButton* backButton = new QPushButton("Back");
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

   buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
   buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
   buttonLayout->addStretch();
   buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

   buttonWidget->setLayout(buttonLayout);
   buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

   // *** CONTENITORE DESTRO ***
   QVBoxLayout* rightLayout = new QVBoxLayout();
   rightLayout->addWidget(infoWidget, 1);
   rightLayout->addWidget(buttonWidget, 0);
   widget->setLayout(mainLayout);
   topLayout->addLayout(rightLayout);
   mainLayout->addLayout(topLayout);

   mainLayout->addLayout(infoLayout);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(movie.getImage()));
    int imageHeight = widget->parentWidget()->height();
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(40, 0, 40, 0); // Margini laterali

    QLabel* titleLabel = new QLabel(QString::fromStdString(movie.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    infoLayout->addSpacing(65); // Spazio prima del titolo
    infoLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(movie.getYear()));
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(movie.getDescription()));
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(movie.getGenre()));
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(movie.getCountry()));
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);
   QPixmap pixmap(QString::fromStdString(movie.getImage()));
    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit
   QLabel* label = new QLabel(QString::fromStdString(movie.getTitle()));  
   QLabel* directorLabel = new QLabel("Director:");  
   QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(movie.getDirector()));
   directorEdit->setReadOnly(true);
   label->setFont(font);  
   infoLayout->addWidget(label);  

   infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

   QLabel* screenwriterLabel = new QLabel("Screenwriter:");  
   QLineEdit* screenwriterEdit = new QLineEdit(QString::fromStdString(movie.getScreenwriter()));  
   screenwriterEdit->setReadOnly(true);
   infoLayout->addWidget(directorLabel);  
   infoLayout->addWidget(directorEdit);  

   infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

   QLabel* lengthLabel = new QLabel("Length:");  
   QLineEdit* lengthEdit = new QLineEdit(QString::number(movie.getLength()));  
   lengthEdit->setReadOnly(true);
   infoLayout->addWidget(screenwriterLabel);  
   infoLayout->addWidget(screenwriterEdit);  

   infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

   QLabel* prodCompanyLabel = new QLabel("Production Company:");  
   QLineEdit* prodCompanyEdit = new QLineEdit(QString::fromStdString(movie.getProd()));  
   prodCompanyEdit->setReadOnly(true);
   infoLayout->addWidget(lengthLabel);  
   infoLayout->addWidget(lengthEdit);  

   QLabel* prodCompanyLabel = new QLabel("Production Company:");  
   QLineEdit* prodCompanyEdit = new QLineEdit(QString::fromStdString(movie.getProd()));  
   infoLayout->addWidget(prodCompanyLabel);  
   infoLayout->addWidget(prodCompanyEdit);  

   infoLayout->addStretch(); // Spinge tutto in alto
   infoWidget->setLayout(infoLayout);
   infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

   // *** WIDGET CONTENITORE PULSANTE ***
   QWidget* buttonWidget = new QWidget();
   QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

   QPushButton* modifyButton = new QPushButton("Modify");
   modifyButton->setFixedSize(150, 40);
   //QObject::connect(modifyButton, &QPushButton::clicked, widget, &ItemDetailsWidget::modifyItem);
   QPushButton* backButton = new QPushButton("Back");
   backButton->setFixedSize(150, 40);
   QPushButton* saveButton = new QPushButton("Save");
   saveButton->setFixedSize(150, 40);
   saveButton->setEnabled(false);

   QPushButton* backButton = new QPushButton("Back");
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

   buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
   buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
   buttonLayout->addStretch();
   buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

   buttonWidget->setLayout(buttonLayout);
   buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

   // *** CONTENITORE DESTRO ***
   QVBoxLayout* rightLayout = new QVBoxLayout();
   rightLayout->addWidget(infoWidget, 1);
   rightLayout->addWidget(buttonWidget, 0);
   widget->setLayout(mainLayout);
   topLayout->addLayout(rightLayout);
   mainLayout->addLayout(topLayout);

    if (widget->layout() != nullptr) {
        QLayoutItem* item;
        while ((item = widget->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete widget->layout();
    }
			delete item->widget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();
		delete widget->layout();
    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(videogame.getImage()));
    int imageHeight = widget->parentWidget()->height();
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(40, 0, 40, 0); // Margini laterali

    QLabel* titleLabel = new QLabel(QString::fromStdString(videogame.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    infoLayout->addSpacing(65); // Spazio prima del titolo
    infoLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(videogame.getYear()));
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(videogame.getDescription()));
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(videogame.getGenre()));
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(videogame.getCountry()));
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);
   QPixmap pixmap(QString::fromStdString(videogame.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(videogame.getTitle()));  
    QLabel* developerLabel = new QLabel("Developer:");
    QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));
    developerEdit->setReadOnly(true);
    infoLayout->addWidget(developerLabel);
    infoLayout->addWidget(developerEdit);

    infoLayout->addSpacing(60); // Spazio tra coppie di label e line edit

    QLabel* multiplayerLabel = new QLabel("Multiplayer:");
    QLineEdit* multiplayerEdit = new QLineEdit(videogame.getMultiplayer() ? "Yes" : "No");
    multiplayerEdit->setReadOnly(true);
    infoLayout->addWidget(multiplayerLabel);
    infoLayout->addWidget(multiplayerEdit);

   QLabel* multiplayerLabel = new QLabel("Multiplayer:");  
   QLineEdit* multiplayerEdit = new QLineEdit(videogame.getMultiplayer() ? "Yes" : "No");  
   infoLayout->addWidget(multiplayerLabel);  
   infoLayout->addWidget(multiplayerEdit);  

    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    //QObject::connect(modifyButton, &QPushButton::clicked, widget, &ItemDetailsWidget::modifyItem);
    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(infoWidget, Qt::AlignTop);
    rightLayout->addWidget(buttonWidget, Qt::AlignCenter);
    rightLayout->setSpacing(0);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);
    saveButton->setEnabled(false);
    widget->setLayout(mainLayout);
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);  
}


