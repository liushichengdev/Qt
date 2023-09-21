#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDockWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //消除中间窗体
    QWidget *central=this->takeCentralWidget();
    if(central!=nullptr) delete central;
    //允许嵌套dockwidget
    this->setDockNestingEnabled(true);

    dock_Image = new QDockWidget(tr("图像"), this);
    dock_Image->setTitleBarWidget(nullptr);
    dock_Image->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);         // 设置为可移动可浮动，但不可关闭
    dock_Image->setAllowedAreas(Qt::BottomDockWidgetArea);  // 可移动范围：左右
    dock_Image->setMinimumSize(QMainWindow::width()/2, 600);   // 设置最小宽高

    //创建窗口
    dock_Tool = new QDockWidget(tr("工具箱"), this);           // 工具箱窗口,若想设置特征或移动范围，方法同上。
    dock_Geom = new QDockWidget(tr("几何变换"), this);          // 几何变换窗口
    dock_Gray = new QDockWidget(tr("灰度变换"), this);          // 灰度变换窗口
    dock_Enhance = new QDockWidget(tr("图像增强"), this);       // 图像增强窗口
    dock_Morp = new QDockWidget(tr("形态学处理"), this);     // 形态学处理窗口
    dock_Color = new QDockWidget(tr("颜色模型"), this);         // 颜色模型窗口
    dock_Prop = new QDockWidget(tr("属性"), this);                // 属性窗口
    dock_Output = new QDockWidget(tr("输出"), this);          // 输出窗口

    // 进行布局
    setCentralWidget(dock_Image);       // 指定为中心窗口
    addDockWidget(Qt::LeftDockWidgetArea, dock_Tool);
    addDockWidget(Qt::BottomDockWidgetArea, dock_Output);
    addDockWidget(Qt::RightDockWidgetArea, dock_Geom);
    addDockWidget(Qt::RightDockWidgetArea, dock_Gray);
    addDockWidget(Qt::RightDockWidgetArea, dock_Enhance);
    addDockWidget(Qt::RightDockWidgetArea, dock_Morp);
    addDockWidget(Qt::RightDockWidgetArea, dock_Color);
    addDockWidget(Qt::RightDockWidgetArea, dock_Prop);

    // 分割窗口
    splitDockWidget(dock_Tool, dock_Image, Qt::Horizontal);     // 水平
    splitDockWidget(dock_Geom, dock_Output, Qt::Vertical);      // 垂直

    // 合并窗口
    tabifyDockWidget(dock_Geom, dock_Gray);
    tabifyDockWidget(dock_Gray, dock_Enhance);
    tabifyDockWidget(dock_Enhance, dock_Morp);
    tabifyDockWidget(dock_Morp, dock_Color);
    tabifyDockWidget(dock_Output, dock_Prop);

    dock_Geom->raise();             // raise()函数可使指定窗口置于最前
    //dock_Output->raise();

    QDockWidget *dock=new QDockWidget(tr("DockWidget"),this);
    QWidget *widget=new QWidget(dock);
    QPushButton *pButton=new QPushButton(widget);
    widget->setWindowTitle("Widget");

    //dock->setTitleBarWidget(widget);
    //dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    dock->setWidget(widget);

    widget->show();
    dock->show();

    splitDockWidget(dock_Image, dock, Qt::Vertical);      // 垂直
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

