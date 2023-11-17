#include "GuideContent.h"
#include <QStyleOption>
#include <QPainter>

GuideContent::GuideContent(QWidget *parent)
    : QWidget{parent}
{

}

void GuideContent::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
