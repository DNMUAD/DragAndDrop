#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("DragAndDrop");

    a_drop_widget = new DropWidget(this);
    a_table_widget = new TableWidget(this);

    QFrame *frame = new QFrame;
    QHBoxLayout * frameLayout = new QHBoxLayout(frame);
    frameLayout->addWidget(a_table_widget,1);
    frameLayout->addWidget(a_drop_widget,4);
    setCentralWidget(frame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_quit_triggered()
{
    qApp->quit();
}

void MainWindow::on_action_clear_widget_triggered()
{
    a_drop_widget->clear();
}
