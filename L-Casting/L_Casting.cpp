#include "l_casting.h"
#include "CommonDef.h"
#include "NaviBar.h"
#include "./ui_l_casting.h"
#include <QToolBox>
#include <QTreeWidget>
#include <QButtonGroup>
#include <QListWidget>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>
#include <QDockWidget>
#include <QLabel>

L_Casting::L_Casting(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::L_Casting)
{
    ui->setupUi(this);
    this->setBaseSize(APP_WIDTH,APP_HEIGHT);
    this->setStyleSheet("background-color: rgb(255,255,255)");

    // dock masthead in the topdockwidget
    topDockWidget=new QDockWidget();

    if(topDockWidget->titleBarWidget()) delete topDockWidget->titleBarWidget();
    topDockWidget->setTitleBarWidget(new QWidget());

    topDockWidget->setAllowedAreas(Qt::TopDockWidgetArea);
    topDockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    topDockWidget->setWidget(masthead);

    masthead->show();

//    this->addDockWidget(Qt::TopDockWidgetArea,topDockWidget);

    // Navibar DockWidget
    QDockWidget *naviBarDock=new QDockWidget();
    NaviBar *naviBar=new NaviBar();

    // 隐藏DockWidget的标题栏
    if(naviBarDock->titleBarWidget()) delete naviBarDock->titleBarWidget();
    naviBarDock->setTitleBarWidget(new QWidget());

    // initialize
    naviBarDock->setAllowedAreas(Qt::LeftDockWidgetArea);
    naviBarDock->setFeatures(QDockWidget::NoDockWidgetFeatures);

    naviBarDock->setFixedWidth(NAVIBAR_FOLD_WIDTH);

    QVBoxLayout *vBoxLayout=new QVBoxLayout();

    QWidget *widget=new QWidget();
    naviBarDock->setWidget(widget);
    widget->setLayout(vBoxLayout);
    widget->show();

    //
    QLabel *label=new QLabel();
    label->setMaximumHeight(1);
    vBoxLayout->addWidget(label);

    //
    vBoxLayout->addWidget(naviBar);

    this->addDockWidget(Qt::LeftDockWidgetArea,naviBarDock,Qt::Orientation::Vertical);
}

L_Casting::~L_Casting()
{
    delete ui;
}

