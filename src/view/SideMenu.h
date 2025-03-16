#ifndef VIEW_SIDE_H
#define VIEW_SIDE_H
#include <QWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include "LibraryModelFilter.h"

class SideMenu : public QWidget {
	Q_OBJECT
private:
	QPushButton* album;
	QPushButton* book;
	QPushButton* comic;
	QPushButton* movie;
	QPushButton* videogame;
	QSortFilterProxyModel* filterProxy;
public:
	explicit SideMenu(LibraryModelFilter* filterProxy, QWidget* parent=nullptr);

/*-------------------------------------------------------------------*/
signals:
	void categoryChanged(const QString& category);
/*-------------------------------------------------------------------*/
};
#endif