#ifndef SLOTTEDLIST_H
#define SLOTTEDLIST_H
#include <QListWidget>

class SlottedList : public QListWidget
{
    Q_OBJECT
public:
    SlottedList();

public slots:
    void insertInList(QString item);
};

#endif // SLOTTEDLIST_H
