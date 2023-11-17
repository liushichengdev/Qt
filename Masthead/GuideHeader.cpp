#include "CommonDef.h"
#include "GuideButton.h"
#include "GuideHeader.h"
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

GuideHeader::GuideHeader(QWidget *parent)
    : QWidget{parent}
{
    //set geometry
    this->setGeometry(MASTHEAD_START_POS_X,
              MASTHEAD_START_POS_Y,
              GUIDE_HEADER_WIDTH,
              GUIDE_HEADER_HEIGHT);

    //set style
    this->setStyleSheet("GuideHeader{"
                        "background-color: rgb(251,251,253);"
                        "border-width:1px;"
                        "border-style:solid;"
                        //"border-color:gray;"
                        "}");

    hBoxLayout=new QHBoxLayout();
    hBoxLayout->setMargin(0);
    hBoxLayout->setSpacing(9);
    hBoxLayout->addSpacing(MASTHEAD_START_POS_X);
    // Guide Button
    guideButton=new GuideButton(this);
    hBoxLayout->addWidget(guideButton,0,Qt::AlignLeft);

    logo_render=new QLabel("裕龙轧辊",this);
    QFont font;
    font.setFamily("Arial");
    font.setBold(false);
    font.setPointSize(5);

    logo_render->setFont(font);
    hBoxLayout->addWidget(logo_render,0,Qt::AlignLeft);

    hBoxLayout->addSpacing(GUIDE_HEADER_WIDTH);
    this->setLayout(hBoxLayout);

}

GuideHeader::~GuideHeader()
{

}

void GuideHeader::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

GuideButton *GuideHeader::getGuideButton() const
{
    return guideButton;
}
