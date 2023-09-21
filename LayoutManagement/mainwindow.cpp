#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "basedockwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QMenuBar>
#include <QToolBox>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //删除中央窗体
    QWidget *central=this->takeCentralWidget();
    if(central) delete central;
    //允许嵌套Dock
    this->setDockNestingEnabled(true);
    DockWidgetLayout();
    //this->setBaseSize(1920,1080);
    //this->setMinimumSize(1280,720);
    this->setDockNestingEnabled(false);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::DockWidgetLayout()
{
    QWidget *widget=new QWidget();
    widget->setBaseSize(500,500);
    widget->show();
    QMenuBar *menuBar=new QMenuBar(widget);
    QMenu *menu=new QMenu(tr("合同"),widget);
    QMenu *menu1=new QMenu(tr("新建"),widget);
    QMenu *menu2=new QMenu(tr("查询"),widget);
    QMenu *menu3=new QMenu(tr("列表"),widget);
    QMenu *menu4=new QMenu(tr("menu4"),widget);
    QMenu *menu5=new QMenu(tr("menu5"),widget);
    QMenu *menu6=new QMenu(tr("menu6"),widget);
    //QPushButton *pushButton1=new QPushButton();
    //QPushButton *pushButton2=new QPushButton();
    menu1->setSeparatorsCollapsible(false);
    menu1->setTearOffEnabled(true);
    menu->addMenu(menu1);
    menu->addMenu(menu2);
    menu->addMenu(menu3);
    menu1->addMenu(menu4);
    menu1->addMenu(menu5);
    menu1->addMenu(menu6);
    menu->setBaseSize(50,500);
    //pushButton1->setMenu(menu1);

    QDockWidget *widget1=new QDockWidget(this);
    QToolButton *toolButton1=new QToolButton();
    QToolButton *toolButton2=new QToolButton();
    QToolBox *toolBox=new QToolBox(widget1);
    toolBox->addItem(menu,tr("Menu"));
    //toolButton1->setMenu(menu1);
    toolBox->addItem(toolButton1,tr("合同"));
    toolBox->addItem(toolButton2,tr("新建"));
    toolBox->setLineWidth(2);
    //toolBox->setItemText(0,tr("合同"));
    //toolBox->setItemText(1, tr("新建"));
    QGridLayout *layout1=new QGridLayout();
    layout1->addWidget(toolBox,0,0);
    //layout1->addWidget(widget,0,1);
    widget->setLayout(layout1);

    widget1->setWindowTitle("Widget1");
    widget1->setBaseSize(640,500);
    //widget1->setMinimumSize(300,100);
    widget1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    widget1->setWidget(widget);
    //widget1->setLayout(layout1);
    widget1->show();


    QDockWidget *widget2=new QDockWidget(this);
    widget2->setWindowTitle(tr("widget2"));
    widget2->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);

    QDockWidget *widget3=new QDockWidget(this);
    widget3->setWindowTitle(tr("widget3"));
    widget3->setFeatures(QDockWidget::NoDockWidgetFeatures);

    QDockWidget *widget4=new QDockWidget(this);
    widget4->setWindowTitle(tr("widget4"));
    //widget4->setGeometry(600,0,1920,500);

    //widget4->setFixedWidth(QMainWindow::width());
    //widget4->show();

    widget1->setStyleSheet("background-color:white");
    widget2->setStyleSheet("background-color:green");
    widget3->setStyleSheet("background-color:red");
    widget4->setStyleSheet("background-color:yellow");

    //BaseDockWidget *dockwidget=new BaseDockWidget();
    this->addDockWidget(Qt::TopDockWidgetArea,widget1);
    this->addDockWidget(Qt::TopDockWidgetArea,widget2);
    this->addDockWidget(Qt::TopDockWidgetArea,widget3);
    //this->addDockWidget(Qt::BottomDockWidgetArea,widget4);
    this->setCentralWidget(widget4);
    this->splitDockWidget(widget1,widget2,Qt::Horizontal);
    this->splitDockWidget(widget2,widget3,Qt::Horizontal);
    this->splitDockWidget(widget1,widget4,Qt::Vertical);
    //this->splitDockWidget(widget2,widget4,Qt::Vertical);
    //this->splitDockWidget(widget3,widget4,Qt::Vertical);
    //this->addDockWidget(dockwidget);
}
