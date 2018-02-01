#include "cpu.h"
#include <QDebug>
CPU::CPU()
{

}

int CPU::next_move(QSet<int> available, QSet<int> whites, QSet<int> blacks, int color)
{
    QSet<int> best_choice = {11,18,81,88};
    best_choice.intersect(available);
    if(best_choice.count() > 0) return QList<int>::fromSet(best_choice)[0];

    best_choice = {13, 16, 21, 28, 61, 68, 83, 86};
    best_choice.intersect(available);
    if(best_choice.count() > 0) return QList<int>::fromSet(best_choice)[0];

    best_choice = {33, 36, 63, 66};
    best_choice.intersect(available);
    if(best_choice.count() > 0) return QList<int>::fromSet(best_choice)[0];

    return QList<int>::fromSet(available)[0];
}
