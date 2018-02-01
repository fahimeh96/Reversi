#include "slottedlist.h"
#include <QDebug>
SlottedList::SlottedList(): QListWidget()
{

}

void SlottedList::insertInList(QString item)
{
    this->addItem(item);
}
