#include "navibar.h"
#include "CommonDef.h"

NaviBar::NaviBar(QWidget *parent):QListWidget(parent)
{
    this->setFixedWidth(NAVIBAR_FOLD_WIDTH);
    this->setItemAlignment(Qt::AlignCenter);

}



void NaviBar::enterEvent(QEnterEvent *event)
{
    this->setFixedWidth(NAVIBAR_UNFOLD_WIDTH);
    QListWidget::enterEvent(event);
}

void NaviBar::leaveEvent(QEvent *event)
{
    this->setFixedWidth(NAVIBAR_FOLD_WIDTH);
    QListWidget::leaveEvent(event);
}


NaviBar::~NaviBar()
{

}

void NaviBar::addNaviBarItem(const QString &label)
{
    NaviBarItem *item=new NaviBarItem(label);
    this->addItem(item);
}

void NaviBar::addNaviBarItem(NaviBarItem *item)
{
    this->addItem(item);
}
