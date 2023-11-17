#include "CommonDef.h"
#include "Avatar.h"
#include "MastheadEnd.h"
#include <QStyleOption>
#include <QPainter>

MastheadEnd::MastheadEnd(QWidget *parent)
    : QWidget{parent}
{
    // set title

    // set geometry
    this->setGeometry(MASTHEAD_END_POS_X,
                      MASTHEAD_END_POS_Y,
                      MASTHEAD_END_WIDTH,
                      MASTHEAD_END_HEIGHT);

    //
    this->setStyleSheet("QWidget {"
                        //"background:yellow;"
                        "border-color: gray;"
                        "border-style: solid;"
                        "border-width: 0px"
                        "}");


    // Layout and Items
    hBoxLayout= new QHBoxLayout();
    hBoxLayout->setMargin(0);
    hBoxLayout->setSpacing(HBOXLAYOUT_SPACING);


    hBoxLayout->addSpacing(MASTHEAD_END_WIDTH);
    notification=new Notification(this);
    hBoxLayout->addWidget(notification,0, Qt::AlignRight);

    avatar=new Avatar(this);
    hBoxLayout->addWidget(avatar,0, Qt::AlignRight);

    this->setLayout(hBoxLayout);
}


void MastheadEnd::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
