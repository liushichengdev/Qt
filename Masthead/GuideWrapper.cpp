#include "CommonDef.h"
#include "GuideWrapper.h"
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

GuideWrapper::GuideWrapper(QWidget *parent)
    : QWidget{parent}
{
    // set WindowFlags
    this->setWindowFlags(Qt::CustomizeWindowHint);

    // set geometry
    this->setGeometry(0,0,APP_WIDTH,APP_HEIGHT);

    // Layout and widgets
    hBoxLayout=new QHBoxLayout();
    hBoxLayout->setMargin(0);
    hBoxLayout->setSpacing(0);

    // Guide Part
    QWidget *widgetGuide=new QWidget();
    widgetGuide->setGeometry(0,
                             0,
                             GUIDE_WRAPPER_WIDTH,
                             APP_HEIGHT);
    widgetGuide->setFixedWidth(GUIDE_WRAPPER_WIDTH);
    widgetGuide->setStyleSheet("QWidget{"
                               //"background-color: yellow;"
                               //"border-right-width:1px;"
                               //"border-style:solid;"
                               //"border-color:gray;"
                               "}");

    vBoxLayout=new QVBoxLayout();
    vBoxLayout->setMargin(0);
    vBoxLayout->setSpacing(0);

    guideHeader=new GuideHeader();

    //vBoxLayout->addWidget(guideHeader,0,Qt::AlignTop);
    vBoxLayout->addWidget(guideHeader);

    //Guide Content
    guideContent=new GuideContent();

    vBoxLayout->addWidget(guideContent);

    widgetGuide->setLayout(vBoxLayout);
    //widgetGuide->show();
    //qDebug()<<"GuideHeader(in the GuideWrapper) Height: "<<guideHeader->geometry().height();

    hBoxLayout->addWidget(widgetGuide);

    // Flexy Part
    QWidget *widgetFlexy=new QWidget();
    widgetFlexy->setStyleSheet("QWidget{"
                               "background-color: rgba(128,128,128,100);"
                               "border-left-width:1px;"
                               "border-style:solid;"
                               //"border-color:gray;"
                               "}");

    hBoxLayout->addWidget(widgetFlexy);

    this->setLayout(hBoxLayout);

}

GuideWrapper::~GuideWrapper()
{

}

void GuideWrapper::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

GuideHeader *GuideWrapper::getGuideHeader() const
{
    return guideHeader;
}
