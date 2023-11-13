#include "Masthead.h"
#include "CommonDef.h"
#include <QStyleOption>
#include <QPainter>
#include <QLabel>
#include <QDebug>
#include <QSize>

Masthead::Masthead(QWidget *parent, QSize* size)
    : QWidget{parent}
{
    // Title
    this->setWindowIconText("Masthead");

    // set size
    //this->setBaseSize(MASTHEAD_WIDTH,MASTHEAD_HEIGHT);
    this->setMinimumHeight(MASTHEAD_HEIGHT);

    // set geometry
    this->setGeometry(0,0,size->width(),size->height()*MASTHEAD_HEIGHT/APP_HEIGHT);


    // set Style
    this->setStyleSheet("Masthead {"
                        //"background:yellow;"
                        "padding-left:MASTHEAD_PADDING_LEFT;"
                        "padding-right:MASTHEAD_PADDING_RIGHT;"
//                        "border-color:darkblue;"
//                        "border-style:solid;"
//                        "border-width:1px;"
                        "}");

    mastheadStart=new MastheadStart(this,size);

}

void Masthead::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
