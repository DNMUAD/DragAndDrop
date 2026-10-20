#ifndef LISTLABEL_H
#define LISTLABEL_H

#include <QWidget>
#include <QLabel>
#include<QMap>
#include <QVariant>
class ListLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ListLabel(QWidget *parent = 0);
    
    void setData(int role,const QVariant value);
    QVariant Data(const int &role);

signals:

private:
    QMap<int,QVariant> a_map_data;
    
public slots:

    
};

#endif // LISTLABEL_H
