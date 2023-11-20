#include "CommonDef.h"
#include "GuideContentItem.h"
#include <QStyleOption>
#include <QPainter>

GuideContentItem::GuideContentItem(QWidget *parent)
    : QWidget{parent}
{
    // set geometry
    this->setGeometry(0,
                      0,
                      GUIDE_CONTENT_ITEM_WIDTH,
                      GUIDE_CONTENT_ITEM_HEIGHT);

    // set size
    this->setFixedHeight(GUIDE_CONTENT_ITEM_HEIGHT);
    this->setFixedWidth(GUIDE_CONTENT_ITEM_WIDTH);

    // set style
    this->setStyleSheet("QWidget{"
                        "background-color: red;"
                        "border-right-width:1px;"
                        "border-style:solid;"
                        "border-color:gray;"
                        "padding-left:GUIDE_CONTENT_ITME_PADDING_LEFT"
                        //"padding-right:GUIDE_CONTENT_ITME_PADDING_RIGHT"
                        "}");

}

void GuideContentItem::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
