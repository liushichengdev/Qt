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
                        //"border-right-width:1px;"
                        //"border-style:solid;"
                        //"border-color:gray;"
                        "}");

    //
    vBoxLayout=new QVBoxLayout();
    this->setLayout(vBoxLayout);

    vBoxLayout->addWidget(new GuideContentItem());
    vBoxLayout->addWidget(new GuideContentItem());
    vBoxLayout->addWidget(new GuideContentItem());

}

void GuideContent::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
