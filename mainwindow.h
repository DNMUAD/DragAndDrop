#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QHBoxLayout>

#include "tablewidget.h"
#include "dropwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_quit_triggered();

    void on_action_clear_widget_triggered();

private:
    Ui::MainWindow *ui;
    TableWidget *a_table_widget;
    DropWidget *a_drop_widget;
};

#endif // MAINWINDOW_H
