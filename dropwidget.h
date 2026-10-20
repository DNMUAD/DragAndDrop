#ifndef DROPWIDGET_H
#define DROPWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QMouseEvent>
#include <QPixmap>
#include <QList>
#include <QPoint>
#include <QMap>
#include <QPair>
#include <QMutableMapIterator>
#include <QPainter>
#include <QPaintEvent>

class DropWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DropWidget(QWidget *parent = nullptr);
    ~DropWidget();

    QWidget *instanceWidget(const int &index,const QPoint point);
    void clear();

protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);

    void paintEvent(QPaintEvent *);

private:
    QMap<QPair<int,int>,QWidget*> a_map_list_widget;

    QPixmap a_bg_pixmap;
};

#endif // DROPWIDGET_H
