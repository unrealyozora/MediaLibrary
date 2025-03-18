#ifndef VIEW_THUMBNAILDEL_H
#define VIEW_THUMBNAILDEL_H
#include <QStyledItemDelegate>
class ThumbnailDelegate : public QStyledItemDelegate {
	Q_OBJECT
public:
	explicit ThumbnailDelegate(QObject* parent = nullptr);
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};
#endif
