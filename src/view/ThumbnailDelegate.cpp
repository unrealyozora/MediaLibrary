#include "ThumbnailDelegate.h"
#include <QPainter>
const unsigned int BANNER_HEIGHT = 20;
const unsigned int BANNER_COLOR = 0x303030;
const unsigned int BANNER_ALPHA = 200;
const unsigned int BANNER_TEXT_COLOR = 0x0ffffff;
const unsigned int HIGHLIGHT_ALPHA = 100;

ThumbnailDelegate::ThumbnailDelegate(QObject* parent):QStyledItemDelegate(parent){}

void ThumbnailDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const{
	painter->save();
	QPixmap pixmap = index.model()->data(index, Qt::DecorationRole).value<QPixmap>();
	painter->drawPixmap(option.rect.x(), option.rect.y(), pixmap);
	QRect bannerRect = QRect(option.rect.x(), option.rect.y(), pixmap.width(), BANNER_HEIGHT);
	QColor bannerColor = QColor(BANNER_COLOR);
	bannerColor.setAlpha(BANNER_ALPHA);
	painter->fillRect(bannerRect, bannerColor);
	QString filename = index.model()->data(index, Qt::DisplayRole).toString();
	painter->setPen(BANNER_TEXT_COLOR);
	painter->drawText(bannerRect, Qt::AlignCenter, filename);
	if (option.state.testFlag(QStyle::State_Selected)) {
		QColor selectedColor = option.palette.highlight().color();
		selectedColor.setAlpha(HIGHLIGHT_ALPHA);
		painter->fillRect(option.rect, selectedColor);
	}
	painter->restore();
}

QSize ThumbnailDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const{
	const QPixmap& pixmap = index.model()->data(index, Qt::DecorationRole).value<QPixmap>();
	return pixmap.size();
}
