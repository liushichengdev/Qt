#include "CommonDef.h"
#include "Avatar.h"
#include <QMenu>
#include <QAction>
#include <QStyleOption>
#include <QPainter>

Avatar::Avatar()
{

}

Avatar::Avatar(QWidget *parent)
    :QPushButton{parent}
{
    //Icon
    avatarIcon=QIcon(AVATAR_ICON);
    avatarIcon.actualSize(QSize(AVATAR_SIZE_WIDTH,AVATAR_WIDGET_HEIGHT),QIcon::Active,QIcon::On);
    this->setIcon(avatarIcon);
    //this->setIconSize(QSize(AVATAR_SIZE_WIDTH,AVATAR_SIZE_HEIGHT));

    // set Text
    //this->setText("AVATAR");

    // set geometry
    this->setGeometry(0,
                      0,
                      AVATAR_WIDGET_WIDTH,
                      AVATAR_WIDGET_HEIGHT);


    // set Style
    this->setStyleSheet("QPushButton {"
                        //"background:yellow;"
                        "border-color: gray;"
                        "border-style: solid;"
                        "border-width: 0px"
                        "}"
                        "QPushButton::menu-indicator{image:none;}"
                        "QPushButton::icon{""}");

    // Menu
    menu=new QMenu();
    //this->setText("Menu");
    //menu->setIcon(avatarIcon);


//    //menu->setIconSize(QSize(AVATAR_SIZE_WIDTH,AVATAR_SIZE_HEIGHT));

    menu->addAction(new QAction("基本信息"));
    menu->addAction(new QAction("设置"));

    this->setMenu(menu);

}

void Avatar::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QPushButton::paintEvent(event);
}

