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

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel(widget);
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

    // *** INFO (Label accanto alla LineEdit senza spazio extra) ***
    QLabel* authorLabel = new QLabel("Author:", widget);
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(album.getAuthor()));
    infoLayout->addWidget(authorLabel, 4, 0);
    infoLayout->addWidget(authorEdit, 5, 0);

    QLabel* songsLabel = new QLabel("Songs:", widget);
    QLineEdit* songsEdit = new QLineEdit(QString::number(album.getSongs()));
    infoLayout->addWidget(songsLabel, 7, 0);
    infoLayout->addWidget(songsEdit, 8, 0);

    QLabel* lengthLabel = new QLabel("Length:", widget);
    QLineEdit* lengthEdit = new QLineEdit(QString::number(album.getLength()));
    infoLayout->addWidget(lengthLabel, 10, 0);
    infoLayout->addWidget(lengthEdit, 11, 0);

    // **Mantenere compattezza**
    infoLayout->setColumnStretch(0, 0);  // Label non si allarga troppo
    infoLayout->setColumnStretch(1, 1);  // LineEdit occupa più spazio
    infoLayout->setVerticalSpacing(5);   // Riduce lo spazio tra righe

    // *** BACK BUTTON ***
    QPushButton* backButton = new QPushButton("Back", widget);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

    QHBoxLayout* buttonLayout = new QHBoxLayout(widget);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton);

    // *** ASSEMBLAGGIO LAYOUT ***
    QVBoxLayout* rightLayout = new QVBoxLayout(widget);
    rightLayout->addLayout(infoLayout);
    rightLayout->addStretch();  // Spinge il bottone in basso
    rightLayout->addLayout(buttonLayout);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

    //widget->getLayout()->addLayout(mainLayout);
    widget->setLayout(mainLayout);
}



void ItemDetailVisitor::visit(Books& book) {

   QHBoxLayout* mainLayout = new QHBoxLayout(widget);
   QVBoxLayout* infoLayout = new QVBoxLayout(widget);

   QLabel* imageLabel = new QLabel(widget);
   QPixmap pixmap(QString::fromStdString(book.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(book.getTitle()), widget);
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* authorLabel = new QLabel("Author:", widget);
   QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(book.getAuthor()));  
   infoLayout->addWidget(authorLabel);  
   infoLayout->addWidget(authorEdit);  

   QLabel* pagesLabel = new QLabel("Pages:", widget);
   QLineEdit* pagesEdit = new QLineEdit(QString::number(book.getPages()), widget);
   infoLayout->addWidget(pagesLabel);  
   infoLayout->addWidget(pagesEdit);  

   QLabel* publHouseLabel = new QLabel("Publishing House:", widget);
   QLineEdit* publHouseEdit = new QLineEdit(QString::fromStdString(book.getPub()), widget);
   infoLayout->addWidget(publHouseLabel);  
   infoLayout->addWidget(publHouseEdit);  

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back", widget);
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   //widget->getLayout()->addLayout(mainLayout);
   widget->setLayout(mainLayout);
}  

void ItemDetailVisitor::visit(Comic& comic) {

	QHBoxLayout* mainLayout = new QHBoxLayout(widget);
	QVBoxLayout* infoLayout = new QVBoxLayout(widget);

   QLabel* imageLabel = new QLabel(widget);
   QPixmap pixmap(QString::fromStdString(comic.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(comic.getTitle()), widget);
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* authorLabel = new QLabel("Author:", widget);
   QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(comic.getAuthor()), widget);
   infoLayout->addWidget(authorLabel);  
   infoLayout->addWidget(authorEdit);  

   QLabel* chaptersLabel = new QLabel("Chapters:");  
   QLineEdit* chaptersEdit = new QLineEdit(QString::number(comic.getChapters()), widget);
   infoLayout->addWidget(chaptersLabel);  
   infoLayout->addWidget(chaptersEdit);  

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back", widget);
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   widget->setLayout(mainLayout);
}  

void ItemDetailVisitor::visit(Movie& movie) {

	QHBoxLayout* mainLayout = new QHBoxLayout(widget);
	QVBoxLayout* infoLayout = new QVBoxLayout(widget);

   QLabel* imageLabel = new QLabel(widget);
   QPixmap pixmap(QString::fromStdString(movie.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(movie.getTitle()), widget);
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* directorLabel = new QLabel("Director:", widget);
   QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(movie.getDirector()), widget);
   infoLayout->addWidget(directorLabel);  
   infoLayout->addWidget(directorEdit);  

   QLabel* screenwriterLabel = new QLabel("Screenwriter:", widget);
   QLineEdit* screenwriterEdit = new QLineEdit(QString::fromStdString(movie.getScreenwriter()), widget);
   infoLayout->addWidget(screenwriterLabel);  
   infoLayout->addWidget(screenwriterEdit);  

   QLabel* lengthLabel = new QLabel("Length:", widget);
   QLineEdit* lengthEdit = new QLineEdit(QString::number(movie.getLength()), widget);
   infoLayout->addWidget(lengthLabel);  
   infoLayout->addWidget(lengthEdit);  

   QLabel* prodCompanyLabel = new QLabel("Production Company:", widget);
   QLineEdit* prodCompanyEdit = new QLineEdit(QString::fromStdString(movie.getProd()), widget);
   infoLayout->addWidget(prodCompanyLabel);  
   infoLayout->addWidget(prodCompanyEdit);  

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back", widget);
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   //widget->getLayout()->addLayout(mainLayout);
   widget->setLayout(mainLayout);
}  

void ItemDetailVisitor::visit(Videogames& videogame) {

	QHBoxLayout* mainLayout = new QHBoxLayout(widget);
	QVBoxLayout* infoLayout = new QVBoxLayout(widget);

   QLabel* imageLabel = new QLabel(widget);
   QPixmap pixmap(QString::fromStdString(videogame.getImage()));
   int imageHeight = widget->parentWidget()->height() - 20; // Subtract 20 to add space at the top and bottom
   imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 2, imageHeight, Qt::KeepAspectRatio)); // Set the image to half the parent widget width
   imageLabel->setMinimumSize(widget->parentWidget()->width() / 2, imageHeight); // Ensure the image label has a minimum size  
   mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter); // Center the image  

   QLabel* label = new QLabel(QString::fromStdString(videogame.getTitle()), widget);
   QFont font = label->font();  
   font.setPointSize(16); // Set the font size for the title  
   label->setFont(font);  
   infoLayout->addWidget(label);  

   QLabel* developerLabel = new QLabel("Developer:", widget);
   QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()), widget);
   infoLayout->addWidget(developerLabel);  
   infoLayout->addWidget(developerEdit);  

   QLabel* multiplayerLabel = new QLabel("Multiplayer:", widget);
   QLineEdit* multiplayerEdit = new QLineEdit(videogame.getMultiplayer() ? "Yes" : "No", widget);
   infoLayout->addWidget(multiplayerLabel);  
   infoLayout->addWidget(multiplayerEdit);  

   infoLayout->setSpacing(0); // Set the spacing between components  
   infoLayout->setContentsMargins(0, 0, 30, 20);

   QPushButton* backButton = new QPushButton("Back", widget);
   QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
   infoLayout->addWidget(backButton);

   mainLayout->addLayout(infoLayout);
   //widget->getLayout()->addLayout(mainLayout);
   widget->setLayout(mainLayout);
}


