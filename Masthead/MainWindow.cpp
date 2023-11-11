#include "MainWindow.h"
#include "CommonDef.h"
#include "./ui_MainWindow.h"
#include <QDockWidget>
#include <QScreen>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 去除标题栏，菜单栏后的宽高
    screenSize=QApplication::primaryScreen()->availableVirtualSize();
    qDebug()<<"Width: "<<screenSize.width();
    qDebug()<<"Height: "<<screenSize.height();

    //set size
    this->setGeometry(0,0,screenSize.width(),screenSize.height());
    //this->setMaximumSize(screenSize.width(),screenSize.height());
    this->setBaseSize(APP_WIDTH,APP_HEIGHT);

    masthead=new Masthead(ui->centralwidget,&screenSize);



}

MainWindow::~MainWindow()
{
    delete ui;
}

