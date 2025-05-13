#include "StyledButton.h"
#include <QDebug>
StyledButton::StyledButton(const QString &text, QWidget *parent):QPushButton(parent){
    setText(text);
    setStyleSheet("QPushButton { background-color:rgb(121, 121, 121); }"
        "QPushButton:disabled { color: rgb(85, 85, 85); background-color: rgb(180, 180, 180); }");

    setFixedSize(150, 40);
    
}