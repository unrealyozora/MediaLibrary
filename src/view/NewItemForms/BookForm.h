#ifndef VIEW_BOOK_FORM_H
#define VIEW_BOOK_FORM_H
#include "NewItemForm.h"
class BookForm : public NewItemForm {
	Q_OBJECT
private:
	QLineEdit* length = nullptr;
	QLineEdit* bookPublHouse = nullptr;
public:
	explicit BookForm(QWidget* parent = nullptr);
	void onAccepted() override;
	virtual bool validateInputs() override;
	virtual void enableButton() override;
};
#endif