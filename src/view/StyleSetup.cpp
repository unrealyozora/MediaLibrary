#include "StyleSetup.h"
#include <QStyleFactory>
#include <QPalette>
namespace StyleSetup {
    void SetStyle(QApplication& app) {
        QApplication::setStyle(QStyleFactory::create("Fusion"));

        // Crea una palette chiara personalizzata
        QPalette lightPalette;
        lightPalette.setColor(QPalette::Window, QColor(255, 255, 255));
        lightPalette.setColor(QPalette::WindowText, Qt::black);
        lightPalette.setColor(QPalette::Base, QColor(245, 245, 245));
        lightPalette.setColor(QPalette::AlternateBase, QColor(230, 230, 230));
        lightPalette.setColor(QPalette::ToolTipBase, Qt::white);
        lightPalette.setColor(QPalette::ToolTipText, Qt::black);
        lightPalette.setColor(QPalette::Text, Qt::black);
        lightPalette.setColor(QPalette::Button, QColor(245, 245, 245));
        lightPalette.setColor(QPalette::ButtonText, Qt::black);
        lightPalette.setColor(QPalette::BrightText, Qt::red);
        lightPalette.setColor(QPalette::Highlight, QColor(76, 163, 224));  // azzurro evidenziazione
        lightPalette.setColor(QPalette::HighlightedText, Qt::white);

        // Applica la palette
        app.setPalette(lightPalette);  // o Default
    }
}

