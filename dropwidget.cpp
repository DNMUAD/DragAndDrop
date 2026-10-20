#include "dropwidget.h"

#include "dragwidgetlineedit.h"
#include "dragwidgetpushbutton.h"
#include "dragtestwidget.h"

DropWidget::DropWidget(QWidget *parent)
    : QWidget{parent}
{
    setAcceptDrops(true);
    a_bg_pixmap = QPixmap(":/DropWidget/bg/wave.png");
}

DropWidget::~DropWidget()
{
}

QWidget *DropWidget::instanceWidget(const int &index,const QPoint point)
{
    int _map_size = a_map_list_widget.size();
    switch(index)
    {
    case 0:
    {
        DragWidgetLineEdit *_drag_widget_line_edit = new DragWidgetLineEdit(this,index,_map_size);
        _drag_widget_line_edit->move(point);
        _drag_widget_line_edit->show();
        _drag_widget_line_edit->setText(QString::number(index) + "-" + QString::number(_map_size));
        a_map_list_widget[QPair<int,int>(index,_map_size)] = _drag_widget_line_edit;
    }
    break;
    case 1:
    {
        DragWidgetPushButton *_drag_widget_push_button = new DragWidgetPushButton(this,index,_map_size);
        _drag_widget_push_button->move(point);
        _drag_widget_push_button->show();
        _drag_widget_push_button->setText(QString::number(index) + "-" + QString::number(_map_size));
        a_map_list_widget[QPair<int,int>(index,_map_size)] = _drag_widget_push_button;
    }
    break;
    case 2:
    {
        DragTestWidget *_drag_widget_test = new DragTestWidget(this,index,_map_size);
        _drag_widget_test->move(point);
        _drag_widget_test->show();
        a_map_list_widget[QPair<int,int>(index,_map_size)] = _drag_widget_test;
    }
    break;
    default:
        break;
    }

    return nullptr;
}

void DropWidget::clear()
{
    QMutableMapIterator<QPair<int,int>,QWidget*> _go_through(a_map_list_widget);
    for(;_go_through.hasNext();)
    {
        _go_through.next().value();
        QWidget* _widget  = _go_through.value();
        delete _widget;
    }
    a_map_list_widget.clear();
}

void DropWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain") || event->mimeData()->hasFormat("applicaion/widget"))
        event->accept();
    else
        event->ignore();
}

void DropWidget::dragMoveEvent(QDragMoveEvent *event)
{
    (void)event;
}

void DropWidget::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain"))
    {
        QByteArray _itemData = event->mimeData()->data("text/plain");
        QDataStream _dataStream(&_itemData,QIODevice::ReadOnly);
        int _index;
        _dataStream >> _index;

        event->setDropAction(Qt::MoveAction);//默认行为
        event->accept();//启用接受

        instanceWidget(_index,event->pos());

    }else if(event->mimeData()->hasFormat("applicaion/widget"))
    {
        QByteArray _itemData = event->mimeData()->data("applicaion/widget");
        QDataStream _dataStream(&_itemData,QIODevice::ReadOnly);
        int _prime_index;
        int _sub_index;

        _dataStream >> _prime_index >> _sub_index;

        event->setDropAction(Qt::MoveAction);//默认行为
        event->accept();//启用接受

        a_map_list_widget[QPair<int,int>(_prime_index,_sub_index)]->move(event->pos());
    }
}

void DropWidget::paintEvent(QPaintEvent *event)
{
    (void)(event);
    QPainter _painter(this);
    _painter.drawPixmap(rect(),a_bg_pixmap);

}
