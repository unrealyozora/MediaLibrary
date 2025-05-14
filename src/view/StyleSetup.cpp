#include "StyleSetup.h"
#include <QStyleFactory>
#include <QPalette>
namespace StyleSetup {
    void SetStyle(QApplication& app) {
        QApplication::setStyle(QStyleFactory::create("Fusion"));

        QPalette lightPalette;
        lightPalette.setColor(QPalette::Window, QColor(212, 212, 212));
        lightPalette.setColor(QPalette::WindowText, Qt::black);
        lightPalette.setColor(QPalette::Base, QColor(240, 240, 240));
        lightPalette.setColor(QPalette::AlternateBase, QColor(230, 230, 230));
        lightPalette.setColor(QPalette::ToolTipBase, Qt::white);
        lightPalette.setColor(QPalette::ToolTipText, Qt::black);
        lightPalette.setColor(QPalette::Text, Qt::black);
        lightPalette.setColor(QPalette::Button, QColor(212, 212, 212));
        lightPalette.setColor(QPalette::ButtonText, Qt::black);
        lightPalette.setColor(QPalette::BrightText, Qt::red);
        lightPalette.setColor(QPalette::Highlight, QColor(76, 163, 224));
        lightPalette.setColor(QPalette::HighlightedText, Qt::white);
        lightPalette.setColor(QPalette::PlaceholderText, Qt::black);

       

        // Applica la palette
        app.setPalette(lightPalette);
    }
}

