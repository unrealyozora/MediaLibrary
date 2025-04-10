#include "QOverlayButton.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QMenu>
QOverlayButton::QOverlayButton(QWidget* parent):QWidget(parent){
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAttribute(Qt::WA_NoSystemBackground);
    setStyleSheet("background: rgba(0,0,0,50);");

    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->setContentsMargins(0,0,10,10);
    layout->setAlignment(Qt::AlignBottom|Qt::AlignRight);

    QPushButton* button= new QPushButton("New Item", this);
    button->setFixedSize(120,50);
    QMenu* buttonMenu = new QMenu(this);
    QAction* newAlbum = new QAction("Add album", buttonMenu);
	QAction* newBook = new QAction("Add book", buttonMenu);
	QAction* newComic = new QAction("Add comic", buttonMenu);
	QAction* newMovie = new QAction("Add movie", buttonMenu);
	QAction* newVideogame = new QAction("Add videogame", buttonMenu);
	buttonMenu->addAction(newAlbum);
	buttonMenu->addAction(newBook);
	buttonMenu->addAction(newComic);
	buttonMenu->addAction(newMovie);
	buttonMenu->addAction(newVideogame);
    layout->addWidget(button);
}

void QOverlayButton::resizeEvent(QResizeEvent* event) {
    setGeometry(0,0,parentWidget()->width(), parentWidget()->height());
    QWidget::resizeEvent(event);
}