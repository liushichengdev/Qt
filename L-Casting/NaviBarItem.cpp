#include "CommonDef.h"
#include "NaviBarItem.h"


NaviBarItem::NaviBarItem(QListWidget *parent, int type):QListWidgetItem(parent,type)
{
    this->setTextAlignment(Qt::AlignLeft);
    this->setItemSize();
}

NaviBarItem::NaviBarItem(const QString &text, QListWidget *parent, int type)
    :QListWidgetItem(text,parent, type)
{
    this->setTextAlignment(Qt::AlignLeft);
    this->setItemSize();
}

NaviBarItem::NaviBarItem(const QIcon &icon, const QString &text, QListWidget *parent, int type)
    :QListWidgetItem(icon,text,parent, type)
{
    this->setTextAlignment(Qt::AlignLeft);
    this->setItemSize();
}

void NaviBarItem::enterEvent(QEnterEvent *event)
{
    //this->setFixedWidth(NAVIBAR_UNFOLD_WIDTH);
}

void NaviBarItem::leaveEvent(QEvent *event)
{
    //this->setFixedWidth(NAVIBAR_FOLD_WIDTH);
}

NaviBarItem::~NaviBarItem()
{

}


void NaviBarItem::setItemSize()
{
    itemSize.setWidth(NAVIBAR_ITEM_GRID_SIZE_WIDTH);
    itemSize.setHeight(NAVIBAR_ITEM_GRID_SIZE_HEIGHT);
}
