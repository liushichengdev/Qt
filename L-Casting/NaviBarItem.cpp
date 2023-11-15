#include "CommonDef.h"
#include "NaviBarItem.h"


NaviBarItem::NaviBarItem(const QString &text, QWidget *parent, Qt::WindowFlags f)
    :QWidget(parent, Qt::WindowFlags())
{
    menu=new QMenu();
    menu->setSeparatorsCollapsible(false);
    menu->setTearOffEnabled(false);

    lButton=new LPushButton(text);

    lButton->setMenu(menu);
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

void NaviBarItem::AddNaviBarSubItem(const QString &label)
{
    QAction *action = new QAction("label");

    this->menu->addAction(action);
}


void NaviBarItem::setItemSize()
{
    itemSize.setWidth(NAVIBAR_ITEM_WITH);
    itemSize.setHeight(NAVIBAR_ITEM_HEIHGT);
}
