#ifndef VIEW_BOOK_FORM_H
#define VIEW_BOOK_FORM_H
#include "NewItemForm.h"
class BookForm : public NewItemForm {
	Q_OBJECT
private:
	QLineEdit* bookPublHouse = nullptr;
public:
	explicit BookForm(QWidget* parent = nullptr);
	void onAccepted() override;
};
#endif