#ifndef VIEW_VIDEOGAME_FORM_H
#define VIEW_VIDEOGAME_FORM_H
#include "NewItemForm.h"
#include <QComboBox>
class VideogameForm :public NewItemForm {
	Q_OBJECT
private:
	QComboBox* multiplayer = nullptr;
public:
	explicit VideogameForm(QWidget* parent = nullptr);
	void onAccepted() override;
};
#endif
