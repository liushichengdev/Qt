#include "NaviBar.h"
#include "CommonDef.h"

NaviBar::NaviBar(const QString &title, QWidget *parent, Qt::WindowFlags flags)
{

}

NaviBar::NaviBar(QWidget *parent, Qt::WindowFlags flags):QDockWidget(parent, Qt::WindowFlags())
{
    // 隐藏DockWidget的标题栏
    if(this->titleBarWidget()) delete this->titleBarWidget();
    this->setTitleBarWidget(new QWidget());

    this->setWidget(widget);
    widget->setLayout(vBoxLayout);

    // 解决 setMinmumSize:  Negative size (x, -1) are not possible
//    QLabel *tempLabel= new QLabel("");
//    tempLabel->setMaximumHeight(1);
//    //this->vBoxLayout->addWidget(tempLabel);

    // initialize
    this->setAllowedAreas(Qt::LeftDockWidgetArea);
    this->setFeatures(QDockWidget::NoDockWidgetFeatures);

    this->setFixedWidth(NAVIBAR_FOLD_WIDTH);
    //this->setItemAlignment(Qt::AlignCenter);
    this->setStyleSheet("QDockWidget {"
                        "border-style :solid; "
                        "border-width : 0px 1px 0px 0px;"
                        "border-color: rgb(240,240,240);"
                        "background-color: rgb(255,255,255);}");

    this->addNaviBarItem("1");
    this->addNaviBarItem("2");
    this->addNaviBarItem("3");
    this->addNaviBarItem("item");

    this->show();
}



void NaviBar::enterEvent(QEnterEvent *event)
{
    this->setFixedWidth(NAVIBAR_UNFOLD_WIDTH);
    QDockWidget::enterEvent(event);
}

void NaviBar::leaveEvent(QEvent *event)
{
    this->setFixedWidth(NAVIBAR_FOLD_WIDTH);
    QDockWidget::leaveEvent(event);
}


NaviBar::~NaviBar()
{

}

void NaviBar::addNaviBarItem(const QString &label)
{
    QMenu *menu=new QMenu(label);

    addNaviBarItem(menu,0,Qt::AlignLeft);
}

void NaviBar::addNaviBarItem(QWidget *item)
{
    this->vBoxLayout->addWidget(item, 0,Qt::AlignLeft);
}

void NaviBar::addNaviBarItem(QWidget *item, int stretch, Qt::Alignment alignment)
{
    this->vBoxLayout->addWidget(item, stretch,alignment);
}

