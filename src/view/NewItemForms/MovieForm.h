#ifndef VIEW_MOVIE_FORM_H
#define VIEW_MOVIE_FORM_H
#include "NewItemForm.h"
class MovieForm :public NewItemForm {
	Q_OBJECT
private:
	QLineEdit* movieScreenWriter;
	QLineEdit* movieProdComp;
public:
	explicit MovieForm(QWidget* parent = nullptr);
	void onAccepted() override;
};
#endif