#ifndef VIEW_SIDE_H
#define VIEW_SIDE_H
#include <QWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QLineEdit>
#include <QStackedWidget>
#include "LibraryModelFilter.h"

class SideMenu : public QWidget {
	Q_OBJECT
private:
	QPushButton* all;
	QPushButton* album;
	QPushButton* book;
	QPushButton* comic;
	QPushButton* movie;
	QPushButton* videogame;
	QSortFilterProxyModel* categoryProxy;
	QSortFilterProxyModel* queryProxy;
	QLineEdit* searchbar;
	QStackedWidget* stackedWidget;
public:
	explicit SideMenu(LibraryCategoryFilter* categoryProxy, LibraryQueryFilter* queryProxy, QStackedWidget* stackedWidget, QWidget* parent=nullptr);

/*-------------------------------------------------------------------*/
signals:
	void categoryChanged(const QString& category);
/*-------------------------------------------------------------------*/
};
#endif