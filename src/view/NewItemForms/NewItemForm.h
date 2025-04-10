#ifndef VIEW_NEWITEM_FORM_H
#define VIEW_NEWITEM_FORM_H
#include <QDialog>
#include <QLineEdit>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QFormLayout>
class NewItemForm : public QDialog {
Q_OBJECT
protected:
	QLineEdit* title=nullptr;
	QLineEdit* year=nullptr;
	QLineEdit* description = nullptr;
	QLineEdit* genre = nullptr;
	QLineEdit* country = nullptr;
	QLineEdit* image = nullptr;
	QLineEdit* author = nullptr;
	QLineEdit* length = nullptr;
	QHBoxLayout* imageLayout = nullptr;
	QFormLayout* formLayout = new QFormLayout(this);
public:
	explicit NewItemForm(QWidget* parent = nullptr);
	virtual void onAccepted() = 0;
};
#endif // VIEW_NEWITEM_FORM_H
