#include "CommonDef.h"
#include "Notification.h"
#include <QStyleOption>
#include <QPainter>

Notification::Notification(QWidget *parent)
    : QPushButton{parent}
{
    // icon
    notificationIcon=QIcon(NOTIFICATION_ICON);
    notificationIcon.actualSize(QSize(NOTIFICATION_ICON_SIZE-10,NOTIFICATION_ICON_SIZE-10),QIcon::Active,QIcon::On);
    this->setIcon(notificationIcon);

    // geometry
    this->setGeometry(0,
                      0,
                      NOTIFICATION_SIZE,
                      NOTIFICATION_SIZE);

    // style
    this->setStyleSheet("QPushButton {"
                        //"background:yellow;"
                        "margin-top:20px;"
                        "margin-right:20px;"
                        "margin-bottom:20px;"
                        "margin-left:20px;"
                        "border-color: gray;"
                        "border-style: solid;"
                        "border-width: 0px"
                        "padding-top:10px;"
                        "padding-right:10px;"
                        "padding-bottom:10px;"
                        "padding-left:10px;"
                        "}");

}

void Notification::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QPushButton::paintEvent(event);
}
