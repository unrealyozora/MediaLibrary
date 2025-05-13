#ifndef VIEW_STYLEDBUTTON_H
#define VIEW_STYLEDBUTTON_H
#include <QPushButton>

class StyledButton: public QPushButton{
Q_OBJECT
public:
    StyledButton(const QString& text, QWidget* parent=0);
};
#endif
