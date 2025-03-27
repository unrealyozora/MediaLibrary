#ifndef VIEW_VIDEOGAME_FORM_H
#define VIEW_VIDEOGAME_FORM_H
#include "NewItemForm.h"

class VideogameForm :public NewItemForm {
	Q_OBJECT
private:
	QLineEdit* multiplayer = nullptr;
public:
	explicit VideogameForm(QWidget* parent = nullptr);
	void onAccepted() override;
};
#endif
