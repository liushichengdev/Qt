#include "CommonDef.h"
#include "Masthead.h"

Masthead::Masthead(QWidget *parent)
    : QWidget{parent}
{
    //set title
    this->setWindowTitle("Masthead");

    //set size
    this->setMinimumHeight(MASTHEAD_HEIGHT);
    this->setMinimumWidth(MASTHEAD_WIDTH);

    //set style
    this->setStyleSheet("QWidget {padding-left:MASTHEAD_PADDING_LEFT;padding-right:MASTHEAD_PADDING_RIGHT}");
}

void Masthead::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
