#include "ItemDetailVisitor.h" 
#include "../library/SaveEditsVisitor.h"
#include "LengthEdit.h"
#include "../library/Library.h"
#include <QString>  
#include <QLayout>  
#include <QFont>  
#include <QLabel>  
#include <QPixmap>
#include <QFormLayout>
#include <QScrollArea>
#include <QValidator>
#include <QMessageBox>
#include <QComboBox>


#include <QDebug>
void ItemDetailVisitor::visit(Album& album) {
    if (widget->layout() != nullptr) {
        QLayoutItem* item;
        while ((item = widget->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete widget->layout();
    }
    QList<QLineEdit*>* editList = new QList<QLineEdit*>;
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(album.getImage()));
    int imageHeight = widget->parentWidget()->height();
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(20, 0, 40, 0); // Margini laterali

    QHBoxLayout* titleLayout = new QHBoxLayout();
    QLineEdit* titleLabel = new QLineEdit(QString::fromStdString(album.getTitle()));
    titleLabel->setReadOnly(true);
    //QLabel* titleLabel = new QLabel(QString::fromStdString(album.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    //titleLabel->setAlignment(Qt::AlignLeft);
    titleLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    QIcon editTitleIcon(":/icons/edit");
    QPushButton* editTitleButton = new QPushButton(editTitleIcon, "Edit");
    editTitleButton->setFixedSize(50, 50);
    editTitleButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    editTitleButton->setFlat(true);
    
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(editTitleButton);
    titleLayout->addStretch();
    infoLayout->addSpacing(65); // Spazio prima del titolo
    infoLayout->addLayout(titleLayout);
    //infoLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(album.getYear()));
    setYearValidator(yearEdit);
    
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(album.getDescription()));
    
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(album.getGenre()));
    
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(album.getCountry()));
    
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(album.getAuthor()));
    
    authorEdit->setReadOnly(true);
    infoLayout->addWidget(authorLabel);
    infoLayout->addWidget(authorEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* songsLabel = new QLabel("Songs:");
    QLineEdit* songsEdit = new QLineEdit(QString::number(album.getSongs()));
    
    songsEdit->setReadOnly(true);
    infoLayout->addWidget(songsLabel);
    infoLayout->addWidget(songsEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* lengthLabel = new QLabel("Length:");
    //QLineEdit* lengthEdit = new QLineEdit(QString::number(album.getLength()));
    QLineEdit* lengthEdit = new LengthEdit(nullptr, album.getLength()); //nullptr va cambiato
    
    
    
    lengthEdit->setReadOnly(true);
    infoLayout->addWidget(lengthLabel);
    infoLayout->addWidget(lengthEdit);
    editList->append(yearEdit);
    editList->append(descriptionEdit);
    editList->append(genreEdit);
    editList->append(countryEdit);
    editList->append(authorEdit);
    editList->append(songsEdit);
    editList->append(lengthEdit);
    setLineEditFlat(editList);
    // *** SCROLL AREA ***
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    //scrollLayout->addWidget(imageLabel);
    scrollLayout->addWidget(infoWidget);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    
    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);
    QObject::connect(saveButton, &QPushButton::clicked, [this, &album, editList]() {
        saveChanges(album, editList);
        });

    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    QObject::connect(modifyButton, &QPushButton::clicked, [this, editList, saveButton]() {
        setLineEditWrite(editList);
        saveButton->setEnabled(true);
        });

    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

    QPushButton* cancelButton = new QPushButton("Cancel");
    cancelButton->setFixedSize(150, 40);
    QObject::connect(cancelButton, &QPushButton::clicked, [this, editList, saveButton]() {
        for (QLineEdit* edit : *editList) {
            LengthEdit* lengthEdit = qobject_cast<LengthEdit*>(edit);
            if (lengthEdit) {
                lengthEdit->undo();  // Ripristina il valore originale con "Minuti"
            }
        }
        setLineEditFlat(editList);  // Rimetti i campi in sola lettura
        saveButton->setEnabled(false);
        });


    QPushButton* deleteButton = new QPushButton("Delete");
    deleteButton->setFixedSize(150, 40);
    QObject::connect(deleteButton, &QPushButton::clicked, [this, titleLabel, yearEdit]() {
        deleteItem(titleLabel->text(), yearEdit->text().toUInt());
        });

    buttonLayout->addWidget(deleteButton,0,Qt::AlignLeft);
    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(cancelButton,0,Qt::AlignLeft);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(scrollArea, 1);
    rightLayout->addWidget(buttonWidget, 0);
    rightLayout->setSpacing(0);

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
    QList<QLineEdit*>* editList = new QList<QLineEdit*>;
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(book.getImage()));
    int imageHeight = widget->parentWidget()->height();
    imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignCenter);

    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(40, 0, 40, 0); // Margini laterali

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
    setYearValidator(yearEdit);
    
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(book.getDescription()));
    
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(book.getGenre()));
    
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(book.getCountry()));
    
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(book.getAuthor()));
    
    authorEdit->setReadOnly(true);
    infoLayout->addWidget(authorLabel);
    infoLayout->addWidget(authorEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* pagesLabel = new QLabel("Pages:");
    QLineEdit* pagesEdit = new QLineEdit(QString::number(book.getPages()));
    
    pagesEdit->setReadOnly(true);
    infoLayout->addWidget(pagesLabel);
    infoLayout->addWidget(pagesEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* publHouseLabel = new QLabel("Publishing House:");
    QLineEdit* publHouseEdit = new QLineEdit(QString::fromStdString(book.getPub()));
    
    publHouseEdit->setReadOnly(true);
    infoLayout->addWidget(publHouseLabel);
    infoLayout->addWidget(publHouseEdit);
    editList->append(yearEdit);
    editList->append(descriptionEdit);
    editList->append(genreEdit);
    editList->append(countryEdit);
    editList->append(authorEdit);
    editList->append(pagesEdit);
    editList->append(publHouseEdit);
    setLineEditFlat(editList);
    // *** SCROLL AREA ***
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    //scrollLayout->addWidget(imageLabel);
    scrollLayout->addWidget(infoWidget);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);
    QPushButton* deleteButton = new QPushButton("Delete");
    deleteButton->setFixedSize(150, 40);
    QObject::connect(deleteButton, &QPushButton::clicked, [this, titleLabel, yearEdit]() {
        deleteItem(titleLabel->text(), yearEdit->text().toUInt());
        });

    buttonLayout->addWidget(deleteButton, 0, Qt::AlignLeft);

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);
    QObject::connect(saveButton, &QPushButton::clicked, [this, &book, editList]() {
        saveChanges(book, editList);
        });

    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    QObject::connect(modifyButton, &QPushButton::clicked, [this, editList, saveButton]() {
        setLineEditWrite(editList);
        saveButton->setEnabled(true);
        });

    

    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

    QPushButton* cancelButton = new QPushButton("Cancel");
    cancelButton->setFixedSize(150, 40);
    QObject::connect(cancelButton, &QPushButton::clicked, [this, editList, saveButton]() {
        setLineEditFlat(editList);
        saveButton->setEnabled(false);
        });

    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(cancelButton, 0, Qt::AlignLeft);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(scrollArea, 1);
    rightLayout->addWidget(buttonWidget, 0);
    rightLayout->setSpacing(0);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

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
    QList<QLineEdit*>* editList= new QList<QLineEdit*>;
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
    setYearValidator(yearEdit);
    
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(comic.getDescription()));
    
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(comic.getGenre()));
    
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(comic.getCountry()));
    
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorEdit = new QLineEdit(QString::fromStdString(comic.getAuthor()));
    
    authorEdit->setReadOnly(true);
    infoLayout->addWidget(authorLabel);
    infoLayout->addWidget(authorEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* chaptersLabel = new QLabel("Chapters:");
    QLineEdit* chaptersEdit = new QLineEdit(QString::number(comic.getChapters()));
    
    chaptersEdit->setReadOnly(true);
    infoLayout->addWidget(chaptersLabel);
    infoLayout->addWidget(chaptersEdit);

    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    editList->append(yearEdit);
    editList->append(descriptionEdit);
    editList->append(genreEdit);
    editList->append(countryEdit);
    editList->append(authorEdit);
    editList->append(chaptersEdit);
    setLineEditFlat(editList);
    // *** SCROLL AREA ***
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    //scrollLayout->addWidget(imageLabel);
    scrollLayout->addWidget(infoWidget);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);
    QObject::connect(saveButton, &QPushButton::clicked, [this, &comic, editList]() {
        saveChanges(comic, editList);
        });

    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    QObject::connect(modifyButton, &QPushButton::clicked, [this, editList,saveButton]() {
        setLineEditWrite(editList);
        saveButton->setEnabled(true);
        });


    QPushButton* cancelButton = new QPushButton("Cancel");
    cancelButton->setFixedSize(150, 40);
    QObject::connect(cancelButton, &QPushButton::clicked, [this, editList,saveButton]() {
        setLineEditFlat(editList);
        saveButton->setEnabled(false);
        });

    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

    QPushButton* deleteButton = new QPushButton("Delete");
    deleteButton->setFixedSize(150, 40);
    QObject::connect(deleteButton, &QPushButton::clicked, [this, titleLabel, yearEdit]() {
        deleteItem(titleLabel->text(), yearEdit->text().toUInt());
        });
    buttonLayout->addWidget(deleteButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(cancelButton, 0, Qt::AlignLeft);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(scrollArea, 1);
    rightLayout->addWidget(buttonWidget, 0);
    rightLayout->setSpacing(0);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

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
    QList<QLineEdit*>* editList = new QList<QLineEdit*>;
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();

    // *** IMMAGINE ***
    QLabel* imageLabel = new QLabel();
    QPixmap pixmap(QString::fromStdString(movie.getImage()));
    int imageHeight = widget->parentWidget()->height();
    //imageLabel->setPixmap(pixmap.scaled(widget->parentWidget()->width() / 3, imageHeight, Qt::KeepAspectRatio));
    imageLabel->setPixmap(pixmap.scaled(400,400, Qt::KeepAspectRatio));
    //imageLabel->setScaledContents(true); // Permette di ridimensionare l'immagine
    topLayout->addWidget(imageLabel, 0, Qt::AlignTop|Qt::AlignLeft);

    // *** WIDGET CONTENITORE INFO ***
    QWidget* infoWidget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(40, 0, 40, 0); // Margini laterali

    QLabel* titleLabel = new QLabel(QString::fromStdString(movie.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignLeft);
    infoLayout->addSpacing(65); // Spazio prima del titolo
    infoLayout->addWidget(titleLabel, 0, Qt::AlignLeft);
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(movie.getYear()));
    setYearValidator(yearEdit);
    
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(movie.getDescription()));
    
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(movie.getGenre()));
    
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(movie.getCountry()));
    
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* directorLabel = new QLabel("Director:");
    QLineEdit* directorEdit = new QLineEdit(QString::fromStdString(movie.getDirector()));
    
    directorEdit->setReadOnly(true);
    infoLayout->addWidget(directorLabel);
    infoLayout->addWidget(directorEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* screenwriterLabel = new QLabel("Screenwriter:");
    QLineEdit* screenwriterEdit = new QLineEdit(QString::fromStdString(movie.getScreenwriter()));
    
    screenwriterEdit->setReadOnly(true);
    infoLayout->addWidget(screenwriterLabel);
    infoLayout->addWidget(screenwriterEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* lengthLabel = new QLabel("Length:");
    QLineEdit* lengthEdit = new LengthEdit(widget,movie.getLength());
    
    lengthEdit->setReadOnly(true);
    infoLayout->addWidget(lengthLabel);
    infoLayout->addWidget(lengthEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* prodCompanyLabel = new QLabel("Production Company:");
    QLineEdit* prodCompanyEdit = new QLineEdit(QString::fromStdString(movie.getProd()));
    
    prodCompanyEdit->setReadOnly(true);
    infoLayout->addWidget(prodCompanyLabel);
    infoLayout->addWidget(prodCompanyEdit);

    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    editList->append(yearEdit);
    editList->append(descriptionEdit);
    editList->append(genreEdit);
    editList->append(countryEdit);
    editList->append(directorEdit);
    editList->append(screenwriterEdit);
    editList->append(lengthEdit);
    editList->append(prodCompanyEdit);
    setLineEditFlat(editList);
    
    // *** SCROLL AREA ***
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    //scrollLayout->addWidget(imageLabel);
    scrollLayout->addWidget(infoWidget);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);

    QPushButton* deleteButton = new QPushButton("Delete");
    deleteButton->setFixedSize(150, 40);
    QObject::connect(deleteButton, &QPushButton::clicked, [this, titleLabel, yearEdit]() {
        deleteItem(titleLabel->text(), yearEdit->text().toUInt());
        });

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);
    QObject::connect(saveButton, &QPushButton::clicked, [this, &movie, editList]() {
        saveChanges(movie, editList);
        });

    buttonLayout->addWidget(deleteButton, 0, Qt::AlignLeft);
    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    QObject::connect(modifyButton, &QPushButton::clicked, [this, editList,saveButton]() {
        setLineEditWrite(editList);
        saveButton->setEnabled(true);
        });


    QPushButton* cancelButton = new QPushButton("Cancel");
    cancelButton->setFixedSize(150, 40);
    QObject::connect(cancelButton, &QPushButton::clicked, [this, editList,saveButton]() {
        for (QLineEdit* edit : *editList) {
            LengthEdit* lengthEdit = qobject_cast<LengthEdit*>(edit);
            if (lengthEdit) {
                lengthEdit->undo();  // Ripristina il valore originale con "Minuti"
            }
        }
        setLineEditFlat(editList);  // Rimetti i campi in sola lettura
        saveButton->setEnabled(false);
        });

    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(cancelButton, 0, Qt::AlignLeft);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(scrollArea, 1);
    rightLayout->addWidget(buttonWidget, 0);
    rightLayout->setSpacing(0);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);
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
    QList<QLineEdit*>* editList = new QList<QLineEdit*>;
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();

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
    infoLayout->addSpacing(spacing); // Spazio prima del titolo
    infoLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    infoLayout->addSpacing(spacing); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    QLineEdit* yearEdit = new QLineEdit(QString::number(videogame.getYear()));
    setYearValidator(yearEdit);
    
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(videogame.getDescription()));
    
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(videogame.getGenre()));
    
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(videogame.getCountry()));
    
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* developerLabel = new QLabel("Developer:");
    QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));
    
    developerEdit->setReadOnly(true);
    infoLayout->addWidget(developerLabel);
    infoLayout->addWidget(developerEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* multiplayerLabel = new QLabel("Multiplayer:");
    //QLineEdit* multiplayerEdit = new QLineEdit(videogame.getMultiplayer() ? "Yes" : "No");
    QComboBox* multiplayerEdit = new QComboBox();
    multiplayerEdit->setEnabled(false);
    multiplayerEdit->setPlaceholderText(videogame.getMultiplayer() ? "Yes" : "No");
    multiplayerEdit->addItem("Yes");
    multiplayerEdit->addItem("No");
    //multiplayerEdit->setReadOnly(true);
    infoLayout->addWidget(multiplayerLabel);
    infoLayout->addWidget(multiplayerEdit);

    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    editList->append(yearEdit);
    editList->append(descriptionEdit);
    editList->append(genreEdit);
    editList->append(countryEdit);
    editList->append(developerEdit);
    setLineEditFlat(editList);
    // *** SCROLL AREA ***
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    //scrollLayout->addWidget(imageLabel);
    scrollLayout->addWidget(infoWidget);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);


    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);
    QPushButton* deleteButton = new QPushButton("Delete");
    deleteButton->setFixedSize(150, 40);
    QObject::connect(deleteButton, &QPushButton::clicked, [this, titleLabel, yearEdit]() {
        deleteItem(titleLabel->text(), yearEdit->text().toUInt());
        });

    buttonLayout->addWidget(deleteButton, 0, Qt::AlignLeft);

    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);
    QObject::connect(saveButton, &QPushButton::clicked, [this, &videogame, editList]() {
        saveChanges(videogame, editList);
        });

    QPushButton* modifyButton = new QPushButton("Modify");
    modifyButton->setFixedSize(150, 40);
    QObject::connect(modifyButton, &QPushButton::clicked, [this, editList, multiplayerEdit,saveButton]() {
        saveButton->setEnabled(true);
        multiplayerEdit->setEnabled(true);
        multiplayerEdit->setStyleSheet(
            "QComboBox:enabled { color: #000000; background-color: #FFFFFF; border: 1px solid #C0C0C0; }"
        );
        setLineEditWrite(editList);
        });

    

    QPushButton* cancelButton = new QPushButton("Cancel");
    cancelButton->setFixedSize(150, 40);
    QObject::connect(cancelButton, &QPushButton::clicked, [this, editList, multiplayerEdit,saveButton]() {
        saveButton->setEnabled(false);
        setLineEditFlat(editList);
        multiplayerEdit->setEnabled(false);
        multiplayerEdit->setStyleSheet(
            "QComboBox:enabled { color: #000000; background-color: #FFFFFF; border: 1px solid #C0C0C0;}"
        );
        });


    QPushButton* backButton = new QPushButton("Back");
    backButton->setFixedSize(150, 40);
    QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);

    buttonLayout->addWidget(modifyButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(saveButton, 0, Qt::AlignLeft);
    buttonLayout->addWidget(cancelButton, 0, Qt::AlignLeft);
    buttonLayout->addStretch();
    buttonLayout->addWidget(backButton, 0, Qt::AlignRight);

    buttonWidget->setLayout(buttonLayout);
    buttonWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    
    // *** CONTENITORE DESTRO ***
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(scrollArea, 1);
    rightLayout->addWidget(buttonWidget,0);
    rightLayout->setSpacing(0);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

    widget->setLayout(mainLayout);
}

void ItemDetailVisitor::setLineEditFlat(const QList<QLineEdit*>* editList){
    for (auto item : *editList){
        item->undo();
        item->setReadOnly(true);
        item->setStyleSheet(
            "QLineEdit[readOnly=\"true\"] { border: none; }"
        );
        item->update();
    }
}

void ItemDetailVisitor::saveChanges(AbstractItem& item, QList<QLineEdit*>* editList){
    SaveEditsVisitor editsVisitor(editList);
    item.accept(editsVisitor);
}

void ItemDetailVisitor::setYearValidator(QLineEdit* yearEdit){
    yearEdit->setValidator(new QIntValidator(0, 2100));
}

void ItemDetailVisitor::deleteItem(const QString& title, const unsigned int year){
    QMessageBox confirmDelete;
    confirmDelete.setWindowTitle("The selected item is being removed");
    confirmDelete.setText("Do you want to remove this item?");
    confirmDelete.setIcon(QMessageBox::Question);
    confirmDelete.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    confirmDelete.setDefaultButton(QMessageBox::Ok);
    if (confirmDelete.exec() == QMessageBox::Ok) {
        Library::getInstance()->removeItem(title.toStdString(), year);
    }
    
}

//solo per test, poi l'estetica finale sarà da cambiare
void ItemDetailVisitor::setLineEditWrite(const QList<QLineEdit*>* editList) {
    for (auto item : *editList) {
        item->setReadOnly(false);
        item->setStyleSheet(
            "QLineEdit[readOnly=\"false\"] { color: #000000; background-color: #FFFFFF; border: none; }"
        );
        item->setText(item->text());
    }
}

