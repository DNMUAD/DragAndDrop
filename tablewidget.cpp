#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent)
    : QTableWidget{parent}
{
    setDragDropMode(QAbstractItemView::DragDrop);
    setDragEnabled(true);
    setAcceptDrops(true);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setHidden(true);
    verticalHeader()->setHidden(true);
    setColumnCount(A_COLUMN_NUM);
    setRowCount(A_ROW_NUM);

    initWidgetName();
}

TableWidget::~TableWidget()
{
}

void TableWidget::addItemData(const int list_count)
{
    insertRow(A_ROW_NUM);
    ListLabel *_data_item = new ListLabel(this);
    _data_item->setAlignment(Qt::AlignCenter);
    _data_item->setText(a_widget_name[list_count]);
    _data_item->setStyleSheet("display: flex;align-items: center;border: 2px solid #acf7ff;color: #000000;font-size: 18px;");
    setCellWidget(A_ROW_NUM,A_COLUMN_STYLE,_data_item);
    _data_item->setData((int)(Qt::UserRole),QVariant(list_count));
}

void TableWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain"))
    {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else
        event->ignore();
}


void TableWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    (void)event;
}

void TableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain"))
        event->accept();
    else
        event->ignore();
}


void TableWidget::startDrag(Qt::DropActions supportedActions)
{
    supportedActions = Qt::CopyAction;

    QPixmap _pixmap;
    ListLabel* _data_item = qobject_cast<ListLabel*>(cellWidget(currentRow(),A_COLUMN_STYLE));
    QByteArray _itemData;
    QDataStream _dataStream(&_itemData,QIODevice::WriteOnly);
    int _index = qvariant_cast<int>(_data_item->Data(Qt::UserRole));

    _dataStream << _index;
    _pixmap = _data_item->grab();

    QMimeData *_mimeData = new QMimeData;
    _mimeData->setData("text/plain",_itemData);

    QDrag *_drag = new QDrag(this);
    _drag->setHotSpot(QPoint(0,0));
    _drag->setMimeData(_mimeData);
    _drag->setPixmap(_pixmap);

    if(_drag->exec(Qt::MoveAction) == Qt::MoveAction)
        ;
}

void TableWidget::initWidgetName()
{
    a_widget_name[0] = "LineEdit";
    a_widget_name[1] = "PushButton";
    a_widget_name[2] = "Test";

    QMap<int, QString>::const_iterator i;
    for (i = a_widget_name.begin(); i != a_widget_name.end(); ++i) {
        addItemData(i.key());
    }
}

void TableWidget::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("text/plain")){
        QByteArray pieceData = event->mimeData()->data("text/plain");
        QDataStream dataStream(&pieceData , QIODevice::ReadOnly);
        int index;
        dataStream >> index;//从QDataStream读取数据

        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else
        event->ignore();
}
