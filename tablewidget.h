#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDragEnterEvent>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include <QByteArray>
#include <QPixmap>
#include <QLabel>
#include <QVariant>
#include <QMap>
#include <QHeaderView>
#include <QMimeData>
#include <QDrag>

#include "listlabel.h"

#define A_ROW_NUM 0
#define A_COLUMN_NUM 1
#define A_COLUMN_STYLE 0

class TableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QWidget *parent = nullptr);
    ~TableWidget();

    void addItemData(const int list_count);

public slots:

protected:
    void dragMoveEvent(QDragMoveEvent *);
    void dragLeaveEvent(QDragLeaveEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);
    void startDrag ( Qt::DropActions supportedActions );

private:
    QMap<int,QString> a_widget_name;

    ListLabel *list_label;

private:
    void initWidgetName();
};

#endif // TABLEWIDGET_H
