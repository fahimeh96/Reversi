#ifndef BUTTON_H
#define BUTTON_H
#include <QPushButton>
#include <QGraphicsDropShadowEffect>

class Button : public QPushButton
{
public:
    bool is_glowing;
    int number;
    Button(QWidget *parent, int x, int y);
    void changeBlack();
    void changeWhite();
    void changeHover(int color);
};

#endif // BUTTON_H
