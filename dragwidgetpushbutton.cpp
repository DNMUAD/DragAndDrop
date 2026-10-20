#include "dragwidgetpushbutton.h"

DragWidgetPushButton::DragWidgetPushButton(QWidget *parent,const int prime_index,const int sub_index) :
    QPushButton(parent),
    a_prime_index(prime_index),
    a_sub_index(sub_index)
{
    setEnabled(true);
    a_drag_start_position = QPoint();
}

void DragWidgetPushButton::performDrag()
{
    // 创建一个QDrag对象并设置拖拽的数据（如果需要）
    QDrag* _drag = new QDrag(this);
    QMimeData* _mimeData = new QMimeData;
    QByteArray _itemData;
    QDataStream _dataStream(&_itemData,QIODevice::WriteOnly);
    // 添加拖拽的数据，例如文本、图像等
    _dataStream << a_prime_index << a_sub_index;

    _mimeData->setData("applicaion/widget",_itemData);

    _drag->setMimeData(_mimeData);

    // 设置拖拽的图标，如果需要的话
    QPixmap pixmap = this->grab();
    _drag->setHotSpot(QPoint(0,0));
    _drag->setPixmap(pixmap);

    // 执行拖拽操作
    _drag->exec(Qt::MoveAction);
}

void DragWidgetPushButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 记录鼠标点击的位置，以便在移动中使用
        a_drag_start_position = event->pos();
    }
}

void DragWidgetPushButton::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int _distance = (event->pos() - a_drag_start_position).manhattanLength();//返回一个向量值
        if (_distance >= QApplication::startDragDistance())
        {
            // 开始拖拽
            performDrag();
        }
    }
}
