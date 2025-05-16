#ifndef VIEW_COMIC_FORM_H
#define VIEW_COMIC_FORM_H
#include "NewItemForm.h"

class ComicForm :public NewItemForm {
	Q_OBJECT
private:
	QLineEdit* length = nullptr;
public:
	explicit ComicForm(QWidget* parent = nullptr);
	void onAccepted() override;
	virtual bool validateInputs() const override;
	virtual void enableButton() override;
};
#endif