#include "slottedlist.h"
#include <QDebug>
SlottedList::SlottedList(): QListWidget()
{

}

// it's slotted list

void SlottedList::insertInList(QString item)
{
    this->addItem(item);
}
