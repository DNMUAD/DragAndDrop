#ifndef DRAGWIDGETLINEEDIT_H
#define DRAGWIDGETLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPoint>
#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QLineEdit>
#include <QPixmap>

class DragWidgetLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit DragWidgetLineEdit(QWidget *parent = 0,const int prime_index = -1,const int sub_index = -1);
    
    void performDrag();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

signals:
    
public slots:

private:
    QPoint a_drag_start_position;

    const int a_prime_index;
    const int a_sub_index;

    
};

#endif // DRAGWIDGETLINEEDIT_H
