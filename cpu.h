#ifndef CPU_H
#define CPU_H
#include<QSet>

class CPU
{
public:
    CPU();
    int next_move(QSet<int> available, QSet<int> whites, QSet<int> blacks, int color);
};

#endif // CPU_H
