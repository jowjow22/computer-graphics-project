#include "elementscombobox.h"

QList<QString> classItems;

ElementsComboBox::ElementsComboBox(QWidget *parent): QComboBox{parent}
{
    for(QString item : classItems){
        this->addItem(item);
    }
}

void ElementsComboBox::AddObject(QString items){
     classItems.append(items);
}
