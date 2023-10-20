#include "CommonDef.h"
#include "NaviBarItem.h"


NaviBarItem::NaviBarItem(QListWidget *parent, int type):QListWidgetItem(parent,type)
{
    setTextAlignment();
    setItemSize();
}

NaviBarItem::NaviBarItem(const QString &text, QListWidget *parent, int type)
    :QListWidgetItem(text,parent, type)
{
    setTextAlignment();
    setItemSize();
}

NaviBarItem::NaviBarItem(const QIcon &icon, const QString &text, QListWidget *parent, int type)
    :QListWidgetItem(icon,text,parent, type)
{
    setTextAlignment();
    setItemSize();
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

void NaviBarItem::setTextAlignment(Qt::Alignment alignment)
{
    QListWidgetItem::setTextAlignment(alignment);
}

void NaviBarItem::setItemSize()
{
    itemSize.setWidth(NAVIBAR_ITEM_GRID_SIZE_WIDTH);
    itemSize.setHeight(NAVIBAR_ITEM_GRID_SIZE_HEIGHT);
}
