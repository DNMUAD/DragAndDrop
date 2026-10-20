#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPoint>
#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QLineEdit>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QBrush>

class DragTestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DragTestWidget(QWidget *parent = 0,const int prime_index = -1,const int sub_index = -1);
    
    void performDrag();

signals:
    
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    void paintEvent(QPaintEvent *);

public slots:
    
private:
    QPoint a_drag_start_position;

    const int a_prime_index;
    const int a_sub_index;

};

#endif // TESTWIDGET_H
