#include "MastheadStart.h"
#include "CommonDef.h"
#include <QStyleOption>
#include <QPainter>
#include <QApplication>
#include <QScreen>
#include <QDebug>


MastheadStart::MastheadStart(QWidget *parent, QSize *size)
    : QWidget{parent}
{
    // set title
    this->setWindowTitle("Masthead Start");

    // set geometry
//    this->setGeometry(MASTHEAD_START_POS_X*size->width()/APP_WIDTH,
//                      MASTHEAD_START_POS_Y*size->height()/APP_HEIGHT,
//                      size->width()*MASTHEAD_START_WIDTH/APP_WIDTH,
//                      size->height()*MASTHEAD_START_HEIGHT/APP_HEIGHT);
    this->setGeometry(MASTHEAD_START_POS_X,
                      MASTHEAD_START_POS_Y,
                      MASTHEAD_START_WIDTH,
                      MASTHEAD_START_HEIGHT);

    // set style
    this->setStyleSheet("MastheadStart {"
                        //"background:red;"
                        //"border-color: black;"
                        "border-style: solid;"
                        "border-width: 1px"
                        "}");

    _guideButton=new GuideButton(this,size);
}

void MastheadStart::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}


