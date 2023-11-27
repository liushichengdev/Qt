#include "CommonDef.h"
#include "GuideContent.h"
#include "GuideContentItem.h"
#include <QStyleOption>
#include <QPainter>

GuideContent::GuideContent(QWidget *parent)
    : QWidget{parent}
{

    // set geometry
    this->setGeometry(0,
                      0,
                      GUIDE_CONTENT_WIDTH,
                      APP_HEIGHT-GUIDE_HEADER_HEIGHT);
    this->setFixedWidth(GUIDE_CONTENT_WIDTH);
    this->setFixedHeight(APP_HEIGHT-GUIDE_HEADER_HEIGHT);

    // set style
    this->setStyleSheet("QWidget{"
                        "background-color: rgb(251,251,253);"
                        "margin-top:0px;"
                        "margin-right:0px;"
                        "margin-bottom:0px;"
                        "margin-left:0px;"
                        "border-right-width:0px;"
                        "border-style:solid;"
                        "border-color:gray;"
                        "padding-top:0px;"
                        "padding-right:0px;"
                        "padding-bottom:0px;"
                        "padding-left:0px;"
                        "}");

    //
    vBoxLayout=new QVBoxLayout();
    vBoxLayout->setMargin(0);
    vBoxLayout->setSpacing(GUIDE_CONTENT_ITEM_SPACING);
    this->setLayout(vBoxLayout);

    vBoxLayout->addWidget(new GuideContentItem());
    vBoxLayout->addWidget(new GuideContentItem());
    vBoxLayout->addWidget(new GuideContentItem());
    vBoxLayout->addSpacing(APP_HEIGHT);
}

GuideContent::~GuideContent()
{
    delete vBoxLayout;
}

void GuideContent::addGuideContentItem(GuideContentItem *item)
{
    this->vBoxLayout->addWidget(item);
}

void GuideContent::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
