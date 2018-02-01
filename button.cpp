#include "button.h"
#include <QDebug>

Button::Button(QWidget *parent, int x, int y) : QPushButton(parent)
{
    QString style = "QPushButton {"
            "color: #333;"
            "border: 2px solid #555;"
            "border-radius: 37px;"
            "padding: 5px;"
            "background: rgba(160,160,160, 0.45);"
            "}";
    this->setStyleSheet(style);
    this->setGeometry(x, y, 74, 74);
    this->is_glowing = false;
}


void Button::changeBlack()
{
    QString style = "QPushButton {"
            "color: #333;"
            "border: 2px solid #555;"
            "border-radius: 37px;"
            "padding: 5px;"
            "background: qradialgradient(cx: 0.3, cy: -0.4,"
            "fx: 0.3, fy: -0.4,"
            "radius: 1.35, stop: 0 #fff, stop: 1 black);"
            "}";
    this->setStyleSheet(style);
    this->setDisabled(true);
}

void Button::changeWhite()
{
    QString style = "QPushButton {"
            "color: #333;"
            "border: 2px solid #555;"
            "border-radius: 37px;"
            "padding: 5px;"
            "background: qradialgradient(cx: 0.3, cy: -0.4,"
            "fx: 0.3, fy: -0.4,"
            "radius: 1.35, stop: 0 #fff, stop: 1 #cecece);"
            "}";
    this->setStyleSheet(style);
    this->setDisabled(true);
}

void Button::changeHover(int color)
{
    QString style = this->styleSheet();
    if(color == -1){
        style += "QPushButton:hover{"
                 "color: #333;"
                 "border: 2px solid #555;"
                 "border-radius: 37px;"
                 "padding: 5px;"
                 "background: qradialgradient(cx: 0.3, cy: -0.4,"
                 "fx: 0.3, fy: -0.4,"
                 "radius: 1.35, stop: 0 #fff, stop: 1 black);"
                 "}";
    }
    else{
        style += "QPushButton:hover{"
                 "color: #333;"
                 "border: 2px solid #555;"
                 "border-radius: 37px;"
                 "padding: 5px;"
                 "background: qradialgradient(cx: 0.3, cy: -0.4,"
                 "fx: 0.3, fy: -0.4,"
                 "radius: 1.35, stop: 0 #fff, stop: 1 #cecece);"
                 "}";
    }

    this->setStyleSheet(style);

}



