#ifndef VIEW_NEW_TITLE_DIALOG
#define VIEW_NEW_TITLE_DIALOG
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
class NewTitleDialog :public QDialog {
Q_OBJECT
private:
	QLabel* originalTitle;
	QLineEdit titleEdit;
	QDialogButtonBox* buttonBox;
public:
	explicit NewTitleDialog(QLabel* oldTitle, QWidget* parent = nullptr);
public slots:
	void onAccepted();
	void onTextChanged(const QString& text);
};
#endif