#include "GuideButton.h"
#include "CommonDef.h"
#include <QStyleOption>
#include <QPainter>

GuideButton::GuideButton()
{
}

GuideButton::GuideButton(QWidget *parent,QSize *size)
    : QPushButton{parent}
{
    _guideIcon=QIcon(":/icon/application.png");
    this->setIcon(_guideIcon);
    this->setIconSize(QSize(ICON_SIZE*size->width()/APP_WIDTH,
                                    ICON_SIZE*size->width()/APP_WIDTH));

    this->setGeometry(0*size->width()/APP_WIDTH,
                              8*size->height()/APP_HEIGHT,
                              40*size->width()/APP_WIDTH,
                              40*size->height()/APP_HEIGHT);

    this->setStyleSheet("QPushButton{"
                                //"background: gray;"
                                //"border-color:black;"
                                //"border-width: 1px;"
                                //"border-style:solid;"
                                "border-radius:20px;"
                                "opacity:255;"
                                "}");

    this->setMouseTracking(true);
}

void GuideButton::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QPushButton::paintEvent(event);
}

void GuideButton::enterEvent(QEvent *event)
{
    this->setStyleSheet("QPushButton{"
                        "background-color: lightgray;"
                        "border-color:lightgray;"
                        "border-width: 1px;"
                        "border-style:solid;"
                        "border-radius:20px;"
                        "selection-background-color: darkblue;"
                        "}");

    QPushButton::enterEvent(event);
}

void GuideButton::leaveEvent(QEvent *event)
{
    this->setStyleSheet("QPushButton{"
                        //"background-color: black;"
                        "border-color:black;"
                        "border-width: 0px;"
                        "border-style:solid;"
                        "border-radius:20px;"
                        "}");

    QPushButton::leaveEvent(event);
}




