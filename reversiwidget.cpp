#include "reversiwidget.h"
#include <QDebug>

ReversiWidget::ReversiWidget(QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(676,676);
    this->setStyleSheet("background: #178931;");
    QSignalMapper* signalMapper = new QSignalMapper (this);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            Button * button = new Button(this, i * 85 + 3 , j * 85 + 3);
            this->buttons[j * 10 + i + 11] = button;
            button->number = j * 10 + i + 11;
            connect (button, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
            signalMapper -> setMapping(button, button->number);
            button->hide();
        }
    }
    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(clickResponse(int)));

    this->buttons[44]->show();
    this->buttons[44]->changeWhite();
    this->whites.insert(44);
    this->buttons[45]->show();
    this->buttons[45]->changeBlack();
    this->blacks.insert(45);
    this->buttons[54]->show();
    this->buttons[54]->changeBlack();
    this->blacks.insert(54);
    this->buttons[55]->show();
    this->buttons[55]->changeWhite();
    this->whites.insert(55);

    this->currentPlayer = -1;

    connect(this, SIGNAL(GameFinished()), this, SLOT(handleFinish()));
}

// It's git

void ReversiWidget::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    p.setPen(QPen(QColor("#494949")));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            p.drawRect(i*85,j*85, 80, 80);

        }
    }
    p.end();

}

void ReversiWidget::move(int act)
{
    QList<int> directions = {-11, -10, -9, -1, 1, 9 , 10 , 11};
    QSet<int> allInWay;
    int offset = act;

    if(this->currentPlayer == -1){
        this->buttons[act]->changeBlack();
        this->buttons[act]->show();
        this->blacks.insert(act);
        foreach(int direction, directions){
            offset = act;
            while(this->whites.contains(offset + direction)){
                allInWay.insert(offset+direction);
                offset += direction;
            }

            if(this->blacks.contains(offset+direction)){
                foreach(int cell, allInWay){
                    this->buttons[cell]->changeBlack();
                    this->blacks.insert(cell);
                    this->whites.remove(cell);
                }
            }

            allInWay.clear();
        }
    }
    else{
        this->buttons[act]->changeWhite();
        this->whites.insert(act);
        this->buttons[act]->show();
        foreach(int direction, directions){
            offset = act;
            while(this->blacks.contains(offset + direction)){
                allInWay.insert(offset+direction);
                offset += direction;
            }

            if(this->whites.contains(offset+direction)){
                foreach(int cell, allInWay){
                    this->buttons[cell]->changeWhite();
                    this->whites.insert(cell);
                    this->blacks.remove(cell);
                }
            }
            allInWay.clear();
        }
    }

    foreach(int move, this->currentAvailableMoves){
        if(!this->whites.contains(move) && !this->blacks.contains(move)){
            this->buttons[move]->hide();
        }
    }

    emit whiteScoreChanged(QString::number(this->whites.count()));
    emit blackScoreChanged(QString::number(this->blacks.count()));
    if(currentPlayer == 1){
        int row = act/10;
        int column = act % 10;
        QString message = "Selected Row ";
        message.append(QString::number(row));
        message.append(" column ");
        message.append(QString::number(column));
        emit whiteMoved(message);
    }
    else if(currentPlayer == -1){
        int row = act/10;
        int column = act % 10;
        QString message = "Selected Row ";
        message.append(QString::number(row));
        message.append(" column ");
        message.append(QString::number(column));
        emit blackMoved(message);
    }

}

QSet<int> ReversiWidget::availableMoves()
{
    QSet<int> availables;
    QList<int> directions = {-11, -10, -9, -1, 1, 9 , 10 , 11};
    if(this->currentPlayer == -1){
        foreach(int black, this->blacks){
            foreach(int direction, directions){
                if(this->whites.contains(black + direction)){
                    int possible = this->findWhiteEnd(black+direction, direction);
                    if(possible < 90 && possible > 10 && possible % 10 < 9 && possible % 10 > 0)
                    availables.insert(possible);
                }
            }
        }

        availables -= this->blacks;
    }
    else{
        foreach(int white, this->whites){
            foreach(int direction, directions){
                if(this->blacks.contains(white + direction)){
                    int possible = this->findBlackEnd(white+direction, direction);
                    if(possible < 90 && possible > 10 && possible % 10 < 9 && possible % 10 > 0)
                    availables.insert(possible);
                }
            }
        }
        availables -= this->whites;
    }

    currentAvailableMoves = availables;
    return availables;
}

void ReversiWidget::showAvailableMoves()
{
    foreach(int available, this->availableMoves()){
        this->buttons[available]->show();
        this->buttons[available]->changeHover(currentPlayer);
    }
}

int ReversiWidget::findWhiteEnd(int position, int direction)
{
    if(!this->whites.contains(position+direction)) return position+direction;
    return findWhiteEnd(position+direction, direction);
}

int ReversiWidget::findBlackEnd(int position, int direction)
{
    if(!this->blacks.contains(position+direction)) return position+direction;
    return findBlackEnd(position+direction, direction);
}

void ReversiWidget::play(int number)
{
    if(this->CPUs.count() > 0){
        if(this->CPUs.contains(currentPlayer)){
            if(this->availableMoves().count() > 0){
                move(cpu.next_move(this->currentAvailableMoves, this->whites, this->blacks, currentPlayer));
                currentPlayer = currentPlayer * -1;
                if(this->CPUs.count() == 2){
                    play();
                }
                else{
                    if(this->availableMoves().count() > 0){
                        this->showAvailableMoves();
                    }
                    else{
                        emit GameFinished();
                        qDebug() << "finished";
                        return;
                    }

                }
            }
            else{
               currentPlayer = currentPlayer * -1;
               if(this->availableMoves().count() > 0){
                   if(CPUs.contains(currentPlayer)){
                       play();
                   }
                   else{
                       this->showAvailableMoves();
                   }
               }
               else{
                   emit GameFinished();
                   qDebug() << "finished";
                   return;
               }
            }

        }
        else{
            this->move(number);
            currentPlayer = currentPlayer * -1;
            play();
        }
    }
    else{
        this->move(number);
        currentPlayer = currentPlayer * -1;
        if(this->availableMoves().count() == 0){
            if(this->availableMoves().count() == 0){
                emit GameFinished();
                return;
            }
            currentPlayer = currentPlayer * -1;
        }

        this->showAvailableMoves();
    }

}

void ReversiWidget::start(QSet<int> player_colors)
{
    QSet<int> all_color = {-1,1};
    if(player_colors.count() > 0){
        CPUs = all_color - player_colors;
    }
    else{
        CPUs = all_color;
    }
    if(player_colors.contains(currentPlayer)){
        this->availableMoves();
        this->showAvailableMoves();
    }
    else{
        this->play();
    }
}

void ReversiWidget::clickResponse(int number)
{
    this->play(number);
}

void ReversiWidget::handleFinish()
{
    QMessageBox msg;
    if(this->blacks.count() > this->whites.count()){
        msg.setText("Black wins.");
    }
    else if(this->blacks.count() < this->whites.count()){
        msg.setText("White wins.");
    }
    else{
        msg.setText("Draw.");
    }

    msg.exec();

    emit Menu();
    this->parentWidget()->close();
}
