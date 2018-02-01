#ifndef REVERSIWIDGET_H
#define REVERSIWIDGET_H

#include <QWidget>
#include <QMap>
#include <QPainter>
#include <QStyleOption>
#include<QSet>
#include <QSignalMapper>
#include <QMessageBox>
#include "button.h"
#include "cpu.h"

class ReversiWidget : public QWidget
{
    Q_OBJECT
private:
    QMap<int, Button *> buttons;
    int currentPlayer;
    QSet<int> blacks;
    QSet<int> whites;
    QSet<int> currentAvailableMoves;
    QSet<int> CPUs;
    QSet<int> Players;
    CPU cpu;
public:
    explicit ReversiWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void move(int act);
    QSet<int> availableMoves();
    void showAvailableMoves();
    int findWhiteEnd(int position, int direction);
    int findBlackEnd(int position, int direction);
    void play(int number = 0);
    void start(QSet<int> player_colors = {});
signals:
    void whiteScoreChanged(QString score);
    void blackScoreChanged(QString score);
    void whiteMoved(QString move);
    void blackMoved(QString move);
    void GameFinished();
    void Menu();
private slots:
    void clickResponse(int number);
    void handleFinish();
};

#endif // REVERSIWIDGET_H
