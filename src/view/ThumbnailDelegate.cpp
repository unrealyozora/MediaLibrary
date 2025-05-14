#include "ThumbnailDelegate.h"
#include <QPainter>
#include <QStyleOptionViewItem>

const unsigned int BANNER_HEIGHT = 20;
const unsigned int BANNER_COLOR = 0x303030;
const unsigned int BANNER_ALPHA = 200;
const unsigned int BANNER_TEXT_COLOR = 0x0ffffff;
const unsigned int HIGHLIGHT_ALPHA = 100;

// Dimensione fissa per ogni elemento (puoi personalizzarla)
const QSize FIXED_ITEM_SIZE(200, 240);

ThumbnailDelegate::ThumbnailDelegate(QObject* parent) : QStyledItemDelegate(parent) {}

void ThumbnailDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
    painter->save();

    QRect itemRect = option.rect;

    // Evidenziazione selezione
    if (option.state.testFlag(QStyle::State_Selected)) {
        QColor selectedColor = option.palette.highlight().color();
        selectedColor.setAlpha(HIGHLIGHT_ALPHA);
        painter->fillRect(itemRect, selectedColor);
    }

    // Rettangolo di contorno
    painter->setPen(Qt::gray);
    painter->drawRect(itemRect.adjusted(0, 0, -1, -1));  // -1 per non sforare

    // Estrai pixmap
    QPixmap pixmap = index.model()->data(index, Qt::DecorationRole).value<QPixmap>();

    // Calcola posizione centrata
    QSize availableSize(itemRect.width() - 10, itemRect.height() - BANNER_HEIGHT - 10); // margine di 5px
    QPixmap scaled = pixmap.scaled(availableSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QPoint imageTopLeft(
        itemRect.x() + (itemRect.width() - scaled.width()) / 2,
        itemRect.y() + (itemRect.height() - BANNER_HEIGHT - scaled.height()) / 2
    );

    painter->drawPixmap(imageTopLeft, scaled);

    // Banner titolo
    QRect bannerRect(itemRect.x(), itemRect.bottom() - BANNER_HEIGHT + 1, itemRect.width(), BANNER_HEIGHT);
    QColor bannerColor = QColor(BANNER_COLOR);
    bannerColor.setAlpha(BANNER_ALPHA);
    painter->fillRect(bannerRect, bannerColor);

    // Testo
    QString filename = index.model()->data(index, Qt::DisplayRole).toString();
    painter->setPen(BANNER_TEXT_COLOR);

	//Gestiamo i titoli troppo lunghi per essere contenuti nel banner
    QFontMetrics fm(painter->font());
	QString elided = fm.elidedText(filename, Qt::ElideRight, bannerRect.width() - 10); // 10px margine
	painter->drawText(bannerRect, Qt::AlignCenter, elided);


    painter->restore();
}

QSize ThumbnailDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const {
    return FIXED_ITEM_SIZE;
}