#ifndef VIEW_ALBUM_FORM_H
#define VIEW_ALBUM_FORM_H
#include "NewItemForm.h"

class AlbumForm : public NewItemForm {
	Q_OBJECT
private:
	QLineEdit* albumsongs = nullptr;
public:
	explicit AlbumForm(QWidget* parent = nullptr);
	void onAccepted() override;
};
#endif
