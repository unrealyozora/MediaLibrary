#ifndef VIEW_SIDE_H
#define VIEW_SIDE_H
#include <QWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>

class SideMenu : public QWidget {
	Q_OBJECT
private:
	QPushButton* album=new QPushButton("Albums");
	QPushButton* book = new QPushButton("Books");
	QPushButton* comic = new QPushButton("Comics");
	QPushButton* movie = new QPushButton("Movies");
	QPushButton* videogame = new QPushButton("Videogames");
public:
	SideMenu(QWidget* parent=nullptr);
};
#endif