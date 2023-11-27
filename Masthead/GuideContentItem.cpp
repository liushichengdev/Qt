#include "CommonDef.h"
#include "GuideContentItem.h"
#include <QStyleOption>
#include <QPainter>
#include <QAction>
#include <QDebug>

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
    this->setStyleSheet("GuideContentItem{"
                        "background-color:rgb(251,251,253);"
                        "margin-top:0px;"
                        "margin-right:12px;"
                        "margin-bottom:0px;"
                        "margin-left:12px;"
                        "border-radius:5px;"
                        "border-style:solid;"
                        "border-color:gray;"
                        "border-width:0px;"
                        "padding-top:0px;"
                        "padding-right:0px;"
                        "padding-bottom:0px;"
                        "padding-left:0px;"
                        "}");
    //qDebug()<<"GuideContentItem Construction";

    hBoxLayout=new QHBoxLayout(this);
    hBoxLayout->setMargin(0);
    hBoxLayout->setSpacing(9);
    hBoxLayout->addSpacing(MASTHEAD_START_POS_X);

    icon=QIcon(GUIDE_CONTENT_ITEM_ICON);
    iconButton=new QPushButton();
    iconButton->setIcon(icon);
    iconButton->setIconSize(QSize(GUIDE_CONTENT_ITEM_ICON_WITH,GUIDE_CONTENT_ITEM_ICON_HEIGHT));
    hBoxLayout->addWidget(iconButton,0,Qt::AlignLeft);

    textLabel=new QLabel("主要功能",this);
    QFont font;
    font.setFamily(QString("Arial"));
    font.setBold(false);
    font.setPointSize(5);
    textLabel->setFont(font);
    hBoxLayout->addWidget(textLabel,0,Qt::AlignLeft);

    hBoxLayout->addSpacing(GUIDE_CONTENT_ITEM_WIDTH);
    this->setLayout(hBoxLayout);
}

GuideContentItem::~GuideContentItem()
{

}

void GuideContentItem::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}

void GuideContentItem::focusInEvent(QFocusEvent *e)
{
    QWidget::focusInEvent(e);
}

void GuideContentItem::focusOutEvent(QFocusEvent *e)
{
    QWidget::focusOutEvent(e);
}

void GuideContentItem::keyPressEvent(QKeyEvent *e)
{
   QWidget::keyPressEvent(e);
}

void GuideContentItem::enterEvent(QEvent *event)
{
   this->setStyleSheet("*{"
                       "background-color: lightgray;"
                       "margin-top:0px;"
                       "margin-right:12px;"
                       "margin-bottom:0px;"
                       "margin-left:12px;"
                       "border-radius:10px;"
                       "border-style:solid;"
                       "border-color:gray;"
                       "border-width:0px;"
                       "padding-top:0px;"
                       "padding-right:0px;"
                       "padding-bottom:0px;"
                       "padding-left:0px;"
                       "}");

   QWidget::enterEvent(event);
}

void GuideContentItem::leaveEvent(QEvent *event)
{
   this->setStyleSheet("GuideContentItem{"
                       "background-color:rgb(251,251,253);"
                       "margin-top:0px;"
                       "margin-right:12px;"
                       "margin-bottom:0px;"
                       "margin-left:12px;"
                       "border-radius:5px;"
                       "border-style:solid;"
                       "border-color:gray;"
                       "border-width:0px;"
                       "padding-top:0px;"
                       "padding-right:0px;"
                       "padding-bottom:0px;"
                       "padding-left:0px;"
                       "}");

   QWidget::leaveEvent(event);
}
