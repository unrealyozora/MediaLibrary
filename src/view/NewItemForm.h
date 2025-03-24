#ifndef VIEW_NEWITEM_FORM_H
#define VIEW_NEWITEM_FORM_H
#include <QDialog>
#include <QLineEdit>
#include <QTabWidget>
class NewItemForm : public QDialog {
Q_OBJECT
private:
	QLineEdit* title;
	QLineEdit* year;
	QLineEdit* description;
	QLineEdit* genre;
	QLineEdit* country;
	QLineEdit* image;
	QLineEdit* author;
	QLineEdit* length;
	QLineEdit* albumsongs=nullptr;
	QLineEdit* bookPublHouse=nullptr;
	QLineEdit* movieScreenWriter=nullptr;
	QLineEdit* movieProdComp=nullptr;
	QLineEdit* multiplayer=nullptr;
public:
	explicit NewItemForm(QWidget* parent = nullptr);
	void setupAlbumForm();
	void setupBookForm();
	void setupComicForm();
	void setupMovieForm();
	void setupVideogameForm();
	static void initializeAlbumForm();
	static void initializeBookForm();
	static void initializeComicForm();
	static void initializeMovieForm();
	static void initializeVideogameForm();
public slots:
	void onAccepted();
};
#endif
