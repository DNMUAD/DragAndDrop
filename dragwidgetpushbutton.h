#ifndef DARGWIDGETPUSHBUTTON_H
#define DARGWIDGETPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QMouseEvent>
#include <QPoint>
#include <QApplication>
#include <QMouseEvent>
#include <QMimeData>
#include <QDataStream>
#include <QByteArray>
#include <QDrag>

class DragWidgetPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit DragWidgetPushButton(QWidget *parent = 0,const int prime_index = -1,const int sub_index = -1);

    void performDrag();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    
signals:
    
public slots:
    

private:
    QPoint a_drag_start_position;

    const int a_prime_index;
    const int a_sub_index;

};

#endif // DARGWIDGETPUSHBUTTON_H
