#ifndef ELEMENTSCOMBOBOX_H
#define ELEMENTSCOMBOBOX_H

#include <QComboBox>


class ElementsComboBox: public QComboBox
{
public:
    ElementsComboBox(QWidget *parent = nullptr);
    static void AddObject(QString items);
};

#endif // ELEMENTSCOMBOBOX_H
