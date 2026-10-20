#include "dragtestwidget.h"

DragTestWidget::DragTestWidget(QWidget *parent,const int prime_index,const int sub_index) :
    QWidget(parent),
    a_prime_index(prime_index),
    a_sub_index(sub_index)
{
    setEnabled(true);
    a_drag_start_position = QPoint();
}

void DragTestWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 记录鼠标点击的位置，以便在移动中使用
        a_drag_start_position = event->pos();
    }
}

void DragTestWidget::mouseMoveEvent(QMouseEvent *event)
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

void DragTestWidget::paintEvent(QPaintEvent *event)
{
    (void)(event);
    setMinimumSize(100,100);
    QPainter _painter(this);
    _painter.setPen(Qt::SolidLine);
    _painter.setPen(QColor(255,192,203));
    _painter.setBrush(QBrush(QColor(255,192,203)));
    _painter.drawPie(0,24,50,50,0,180*16);
    _painter.drawPie(49,24,50,50,0,180*16);
    _painter.drawPie(0,0,100,100,0,-180*16);
    _painter.setPen(Qt::black);
    _painter.drawText(40,60,tr("TEST"));
}

void DragTestWidget::performDrag()
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
    this->hide();
    _drag->exec(Qt::MoveAction);
    this->show();
}
