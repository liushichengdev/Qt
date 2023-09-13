#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle(tr("MainWindow"));
    createDockWidget(tr("DockWidget1"));

    createDockWidget(tr("DockWidget2"));

    createDockWidget(tr("DockWidget3"));

    //this->showFullScreen();
    this->setAttribute(Qt::WA_TranslucentBackground,false);
    this->setCursor(Qt::CrossCursor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDockWidget(QString str)
{
    QDockWidget *dockWidget=new QDockWidget(str,this);

    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea);

    dockWidget->resize(300,300);

    //dockWidget->setTitleBarWidget(new QDockWidget(tr("NewDockWidget"), dockWidget));
    dockWidget->setWindowFlags(Qt::Widget);
}
