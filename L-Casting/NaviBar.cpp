#include "NaviBar.h"
#include "CommonDef.h"
#include "LPushButton.h"
#include <QPushButton>
#include <QModelIndex>
#include <QToolButton>

NaviBar::NaviBar(QWidget *parent, Qt::WindowFlags flags):QWidget(parent, Qt::WindowFlags())
{


    // 设置导航栏边框
    this->listWidget->setStyleSheet("QListWidget:enabled {"
                        "border-style :solid; "
                        "border-width : 0px 1px 0px 0px;"
                        "border-color: rgb(255,255,255);" //
                        "background-color: rgb(255,255,255);"
                        "margin: 0px 10px 0px 10px}");


    LPushButton *btn1=new LPushButton("Button1");

    //QMenuBar *menuBar1=new QMenuBar();
    //QMenuBar *menuBar2=new QMenuBar();
    QMenu *menu1=new QMenu();
    menu1->setSeparatorsCollapsible(false);
    menu1->setTearOffEnabled(false);
    menu1->addAction(new QAction("1.1"));
    menu1->addAction(new QAction("1.2"));
    menu1->addAction(new QAction("1.3"));
    menu1->setStyleSheet("QAction{text-align:left}");
    //menuBar1->addMenu(menu1);
    menu1->setToolTipsVisible(true);
    btn1->setMenu(menu1);
    //toolButton->setMenu(menu1);
    QPushButton *btn2=new QPushButton("Button2");
    QMenu *menu2=new QMenu("2");
    menu2->addMenu(new QMenu("2.1"));
    menu2->addMenu(new QMenu("2.2"));
    menu2->addMenu(new QMenu("2.3"));
    btn2->setMenu(menu2);
    //menuBar2->addMenu(menu2);
    //menuBar1->setStyleSheet("QMenuBar{border-width:0px}");
    //menuBar2->setStyleSheet("QPushButton{border-width:0px}");
    //this->vBoxLayout->addWidget(menuBar1,0,Qt::AlignTop);
    //this->vBoxLayout->addWidget(menuBar2,0,Qt::AlignTop);
    QListWidgetItem *item1=new QListWidgetItem("");
    QListWidgetItem *item2=new QListWidgetItem("");
    //QListWidgetItem *item3=new QListWidgetItem("item3");
    this->listWidget->addItem(item1);
    this->listWidget->addItem(item2);
    //this->listWidget->addItem(item3);

    this->listWidget->setItemWidget(item1,btn1);
    this->listWidget->setItemWidget(item2,btn2);
    //this->listWidget->setItemWidget(item3,toolButton);

}



void NaviBar::enterEvent(QEnterEvent *event)
{
    this->setFixedWidth(NAVIBAR_UNFOLD_WIDTH);
    QWidget::enterEvent(event);
}

void NaviBar::leaveEvent(QEvent *event)
{
    this->setFixedWidth(NAVIBAR_FOLD_WIDTH);
    QWidget::leaveEvent(event);
}


NaviBar::~NaviBar()
{
    delete listWidget;
}

void NaviBar::AddNaviBarItem(const QString &label)
{
    //
    NaviBarItem *naviBarItem=new NaviBarItem(label);

    //
    QListWidgetItem *item=new QListWidgetItem("");

    //
    this->listWidget->setItemWidget(item,naviBarItem);
}

void NaviBar::AddNaviBarSubItem(NaviBarItem *naviItem, const QString &label)
{
    naviItem->AddNaviBarSubItem(label);
}


