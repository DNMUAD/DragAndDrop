#include "listlabel.h"

ListLabel::ListLabel(QWidget *parent) :
    QLabel(parent)
{
}

void ListLabel::setData(int role,const QVariant value)
{
    a_map_data[role] = value;
}

QVariant ListLabel::Data(const int &role)
{
    return a_map_data[role];
}
