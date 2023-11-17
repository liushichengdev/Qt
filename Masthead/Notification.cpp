#include "CommonDef.h"
#include "Notification.h"
#include <QStyleOption>
#include <QPainter>

Notification::Notification(QWidget *parent)
    : QPushButton{parent}
{
    // icon
    notificationIcon=QIcon(NOTIFICATION_ICON);
    notificationIcon.actualSize(QSize(NOTIFICATION_ICON_SIZE,NOTIFICATION_ICON_SIZE),QIcon::Active,QIcon::On);
    this->setIcon(notificationIcon);

    // geometry
    this->setGeometry(0,
                      0,
                      NOTIFICATION_SIZE,
                      NOTIFICATION_SIZE);

    // style
    this->setStyleSheet("QPushButton {"
                        //"background:yellow;"
                        "border-color: gray;"
                        "border-style: solid;"
                        "border-width: 0px"
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
