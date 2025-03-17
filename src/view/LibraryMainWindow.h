#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H
#include <QMainWindow>
#include <QFileDialog>
#include <QStackedWidget>
#include "ItemDetailWidget.h"
#include "LibraryListModel.h"
#include "LibraryModelFilter.h"
class LibraryMainWindow :public QMainWindow {
	Q_OBJECT
private:
	QStackedWidget* stackedWidget;
	ItemWidget* detailWidget;
	LibraryListModel* model;
	LibraryModelFilter* categoryFilter;
public:
	LibraryMainWindow();
private slots:
	void OpenFile();
	void SaveFile();
	void itemSelected(const QModelIndex& index);
	void backHome();

};
#endif