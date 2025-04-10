#ifndef VIEW_OVERLAY_BUTTON_H
#define VIEW_OVERLAY_BUTTON_H
#include <QWidget>

class QOverlayButton:public QWidget{
    public:
    explicit QOverlayButton(QWidget* parent=nullptr);
    protected:
    void resizeEvent(QResizeEvent* event) override;
};
#endif