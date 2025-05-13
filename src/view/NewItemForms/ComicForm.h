#ifndef VIEW_COMIC_FORM_H
#define VIEW_COMIC_FORM_H
#include "NewItemForm.h"

class ComicForm :public NewItemForm {
	Q_OBJECT
public:
	explicit ComicForm(QWidget* parent = nullptr);
	void onAccepted() override;
	virtual bool validateInputs() override;
	virtual void enableButton() override;
};
#endif