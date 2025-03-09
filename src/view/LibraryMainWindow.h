#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H
#include <QMainWindow>
#include <QFileDialog>
class LibraryMainWindow :public QMainWindow {
	Q_OBJECT
public:
	LibraryMainWindow();
private slots:
	void OpenFile();
};
#endif
