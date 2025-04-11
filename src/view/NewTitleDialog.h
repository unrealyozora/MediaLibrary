#ifndef VIEW_NEW_TITLE_DIALOG
#define VIEW_NEW_TITLE_DIALOG
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
class NewTitleDialog :public QDialog {
Q_OBJECT
private:
	QLabel* originalTitle;
	QLineEdit titleEdit;
public:
	explicit NewTitleDialog(QLabel* oldTitle, QWidget* parent = nullptr);
public slots:
	void onAccepted();
};
#endif