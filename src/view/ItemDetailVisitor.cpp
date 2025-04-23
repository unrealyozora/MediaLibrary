#include "ItemDetailVisitor.h" 
#include "../library/SaveEditsVisitor.h"
#include "LengthEdit.h"
#include "../library/Library.h"
#include "NewTitleDialog.h"
#include <QString>  
#include <QFont>  
#include <QLabel>  
#include <QPixmap>
#include <QFormLayout>
#include <QScrollArea>
#include <QValidator>
#include <QMessageBox>
#include <QComboBox>
#include <QFileDialog>

#include <QDebug>
void ItemDetailVisitor::initialSetup(AbstractItem& item){
    if (widget->layout() != nullptr) {
        QLayoutItem* item;
        while ((item = widget->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete widget->layout();
    }

    editList = new QList<QLineEdit*>;
    mainLayout = new QVBoxLayout();
    topLayout = new QHBoxLayout();

    // *** IMMAGINE ***
    imageLabel = new QLabel();
    QPixmap pixmap;
    if (item.getImage().empty()) {
        pixmap=QPixmap("assets/noImage.jpg");
    }
    else {
        //qDebug() << album.getImage();
        pixmap=QPixmap(QString::fromStdString(item.getImage()));
    }
    imageLabel->setPixmap(pixmap.scaled(400, 400, Qt::KeepAspectRatio));
    topLayout->addWidget(imageLabel, 0, Qt::AlignTop | Qt::AlignLeft);
    QPushButton* changeImageButton = new QPushButton("Change Image");
    topLayout->addWidget(changeImageButton);
    QObject::connect(changeImageButton, &QPushButton::clicked, [this, &item](){
        setNewImage(item);
    });

    infoWidget = new QWidget();
    infoLayout = new QVBoxLayout(infoWidget);
    infoLayout->setContentsMargins(20, 0, 40, 0); // Margini laterali

    titleLayout = new QHBoxLayout();
    titleLabel = new QLabel(QString::fromStdString(item.getTitle()));
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
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
    infoLayout->addSpacing(60); // Spazio aumentato tra titolo e informazioni

    // *** INFO ***
    QLabel* yearLabel = new QLabel("Year:");
    yearEdit = new QLineEdit(QString::number(item.getYear()));
    setYearValidator(yearEdit);
    
    yearEdit->setReadOnly(true);
    infoLayout->addWidget(yearLabel);
    infoLayout->addWidget(yearEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* descriptionLabel = new QLabel("Description:");
    QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(item.getDescription()));
    
    descriptionEdit->setReadOnly(true);
    infoLayout->addWidget(descriptionLabel);
    infoLayout->addWidget(descriptionEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* genreLabel = new QLabel("Genre:");
    QLineEdit* genreEdit = new QLineEdit(QString::fromStdString(item.getGenre()));
    
    genreEdit->setReadOnly(true);
    infoLayout->addWidget(genreLabel);
    infoLayout->addWidget(genreEdit);
    

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* countryLabel = new QLabel("Country:");
    QLineEdit* countryEdit = new QLineEdit(QString::fromStdString(item.getCountry()));
    
    countryEdit->setReadOnly(true);
    infoLayout->addWidget(countryLabel);
    infoLayout->addWidget(countryEdit);
    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit
    editList->append(yearEdit);
    editList->append(descriptionEdit);
    editList->append(genreEdit);
    editList->append(countryEdit);
    // *** WIDGET CONTENITORE PULSANTE ***
    QWidget* buttonWidget = new QWidget();
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);
    QPushButton* saveButton = new QPushButton("Save");
    saveButton->setFixedSize(150, 40);
    saveButton->setEnabled(false);
    QObject::connect(saveButton, &QPushButton::clicked, [this, &item]() {
        saveChanges(item, *titleLabel, editList);
        });
    QObject::connect(editTitleButton, &QPushButton::clicked, [this, saveButton]() {
        NewTitleDialog* newTitleDialog = new NewTitleDialog(titleLabel);
        if (newTitleDialog->exec() == QDialog::Accepted) {
            saveButton->setEnabled(true);
        }
        //aggiungere delete?
        });
        QPushButton* modifyButton = new QPushButton("Modify");
        modifyButton->setFixedSize(150, 40);
        QObject::connect(modifyButton, &QPushButton::clicked, [this,saveButton]() {
            setLineEditWrite(editList);
            saveButton->setEnabled(true);
            });
        QPushButton* backButton = new QPushButton("Back");
        backButton->setFixedSize(150, 40);
        QObject::connect(backButton, &QPushButton::clicked, widget, &ItemDetailsWidget::backToHome);
    
        QPushButton* cancelButton = new QPushButton("Cancel");
        cancelButton->setFixedSize(150, 40);
        QObject::connect(cancelButton, &QPushButton::clicked, [this,saveButton]() {
            for (QLineEdit* edit : *editList) {
                if (qobject_cast<LengthEdit*>(edit)) {
                    qobject_cast<LengthEdit*>(edit)->undo();  // Ripristina il valore originale con "Minuti"
                }
            }
            setLineEditFlat(editList);  // Rimetti i campi in sola lettura
            saveButton->setEnabled(false);
            });
        QPushButton* deleteButton = new QPushButton("Delete");
        deleteButton->setFixedSize(150, 40);
        QObject::connect(deleteButton, &QPushButton::clicked, [this]() {
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
        rightLayout= new QVBoxLayout();
        rightLayout->addWidget(buttonWidget, 0);
        qDebug()<<"initialSetup";
}

void ItemDetailVisitor::finalSetup(AbstractItem& item){
    // *** SCROLL AREA ***
    QScrollArea* scrollArea = new QScrollArea();
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->addWidget(infoWidget);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    // *** CONTENITORE DESTRO ***
    rightLayout = new QVBoxLayout();
    rightLayout->addWidget(scrollArea, 1);
    rightLayout->setSpacing(0);

    topLayout->addLayout(rightLayout);
    mainLayout->addLayout(topLayout);

    widget->setLayout(mainLayout);
}

void ItemDetailVisitor::visit(Album& album) {
    initialSetup(album);
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
    QLineEdit* lengthEdit = new LengthEdit(nullptr, album.getLength()); //nullptr va cambiato

    lengthEdit->setReadOnly(true);
    infoLayout->addWidget(lengthLabel);
    infoLayout->addWidget(lengthEdit);
    editList->append(authorEdit);
    editList->append(songsEdit);
    editList->append(lengthEdit);
    setLineEditFlat(editList);
    finalSetup(album);
}


void ItemDetailVisitor::visit(Books& book) {
    initialSetup(book);
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
    editList->append(authorEdit);
    editList->append(pagesEdit);
    editList->append(publHouseEdit);
    setLineEditFlat(editList);
    finalSetup(book);
}

void ItemDetailVisitor::visit(Comic& comic) {
    initialSetup(comic);
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
    editList->append(authorEdit);
    editList->append(chaptersEdit);
    setLineEditFlat(editList);
    finalSetup(comic);
}

void ItemDetailVisitor::visit(Movie& movie) {
    initialSetup(movie);
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
    editList->append(directorEdit);
    editList->append(screenwriterEdit);
    editList->append(lengthEdit);
    editList->append(prodCompanyEdit);
    setLineEditFlat(editList);
    finalSetup(movie);
}


void ItemDetailVisitor::visit(Videogames& videogame) {
    initialSetup(videogame);
    QLabel* developerLabel = new QLabel("Developer:");
    QLineEdit* developerEdit = new QLineEdit(QString::fromStdString(videogame.getDeveloper()));
    
    developerEdit->setReadOnly(true);
    infoLayout->addWidget(developerLabel);
    infoLayout->addWidget(developerEdit);

    infoLayout->addSpacing(spacing); // Spazio tra coppie di label e line edit

    QLabel* multiplayerLabel = new QLabel("Multiplayer:");
    QComboBox* multiplayerEdit = new QComboBox();
    multiplayerEdit->setEnabled(false);
    multiplayerEdit->setPlaceholderText(videogame.getMultiplayer() ? "Yes" : "No");
    multiplayerEdit->addItem("Yes");
    multiplayerEdit->addItem("No");
    infoLayout->addWidget(multiplayerLabel);
    infoLayout->addWidget(multiplayerEdit);

    infoLayout->addStretch(); // Spinge tutto in alto
    infoWidget->setLayout(infoLayout);
    infoWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    editList->append(developerEdit);
    setLineEditFlat(editList);
    finalSetup(videogame);
}

void ItemDetailVisitor::setLineEditFlat(const QList<QLineEdit*>* editList) const{
    for (auto item : *editList){
        item->undo();
        item->setReadOnly(true);
        item->setStyleSheet(
            "QLineEdit[readOnly=\"true\"] { border: none; }"
        );
        item->update();
    }
}

void ItemDetailVisitor::saveChanges(AbstractItem& item,QLabel& title, QList<QLineEdit*>* editList, QComboBox* multiplayerEdit) const{
    SaveEditsVisitor editsVisitor(title,editList, multiplayerEdit);
    item.accept(editsVisitor);
}

void ItemDetailVisitor::setYearValidator(QLineEdit* yearEdit) const{
    yearEdit->setValidator(new QIntValidator(0, 2100));
}

void ItemDetailVisitor::deleteItem(const QString& title, const unsigned int year) const{
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
void ItemDetailVisitor::setLineEditWrite(const QList<QLineEdit*>* editList) const{
    for (auto item : *editList) {
        item->setReadOnly(false);
        item->setStyleSheet(
            "QLineEdit[readOnly=\"false\"] { color: #000000; background-color: #FFFFFF; border: none; }"
        );
        item->setText(item->text());
    }
}

void ItemDetailVisitor::setNewImage(AbstractItem& item) const{
    QString path = QFileDialog::getOpenFileName(nullptr, "Select a file", "", "Library File (*.jpg *.png)");
    item.setImage(path.toStdString());
    Library::getInstance()->updateItem(item);
    QPixmap newPixmap("assets/noImage.jpg");
}

