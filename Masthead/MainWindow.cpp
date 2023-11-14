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
    qDebug()<<"Screen - Width: "<<screenSize.width()<<" Height: "<<screenSize.height();

    //set size
    //this->setGeometry(0,0,screenSize.width(),screenSize.height());
    this->setGeometry(0,0,APP_WIDTH,APP_HEIGHT);
    //this->setMaximumSize(screenSize.width(),screenSize.height());
    this->setBaseSize(APP_WIDTH,APP_HEIGHT);

    masthead=new Masthead(ui->centralwidget,&screenSize);



}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::resizeEvent(QResizeEvent *event)
//{
//    // 获取当前屏幕的大小
//    QScreen *screen=QApplication::primaryScreen();
//    QSize screenSize = screen->size();

//    qDebug()<<"ScreenSize - Width :"<<screenSize.width()<<" Height: "<<screenSize.height();

//    // 获取窗口的默认大小
//    QSize defaultSize = sizeHint();
//    qDebug()<<"DefaultSize - Width :"<<defaultSize.width()<<" Height: "<<defaultSize.height();

//    // 计算宽度缩放比例和高度缩放比例
//    float widthScale = (float)screenSize.width() / (float)defaultSize.width();
//    float heightScale = (float)screenSize.height() / (float)defaultSize.height();

//    // 应用缩放比例到窗口大小和内容
//    int newWidth = (int)(defaultSize.width() * widthScale);
//    int newHeight = (int)(defaultSize.height() * heightScale);
//    resize(newWidth, newHeight);

//    // 窗口内容缩放
//    setContentsMargins(0, 0, 0, 0); // 确保无边距
//    QWidget::resizeEvent(event); // 调用父类的resizeEvent函数
//}

