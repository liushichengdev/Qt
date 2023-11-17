#include "CommonDef.h"
#include "MastheadCenter.h"
#include "SubFunctionButton.h"
#include <QStyleOption>
#include <QPainter>
#include <QPushButton>

MastheadCenter::MastheadCenter(QWidget *parent, QSize *size)
    : QWidget{parent}
{
    // set title
    //this->setWindowTitle("Masthead Center");

    // set size
    //this->setFixedHeight(MASTHEAD_CENTER_HEIGHT);

    // set geometry
    this->setGeometry(MASTHEAD_CENTER_POS_X,
                      MASTHEAD_CENTER_POS_Y,
                      MASTHEAD_CENTER_WIDTH,
                      MASTHEAD_CENTER_HEIGHT);

    // set style
    this->setStyleSheet("QWidget {"
                        //"background:lightgray;"
                        "border-color: gray;"
                        "border-style: solid;"
                        "border-width: 0px"
                        "}");

    hBoxLayout=new QHBoxLayout();
    hBoxLayout->setMargin(0);
    hBoxLayout->setSpacing(SUBFUNCTION_BTN_SPACING);
    this->setLayout(hBoxLayout);

    SubFunctionButton *btn2=new SubFunctionButton("客户\n管理",this);
    hBoxLayout->addWidget(btn2,0,Qt::AlignLeft);

    SubFunctionButton *btn1=new SubFunctionButton("合同\n管理",this);
    hBoxLayout->addWidget(btn1,0,Qt::AlignLeft);

    SubFunctionButton *btn3=new SubFunctionButton("生产\n进度",this);
    hBoxLayout->addWidget(btn3,0,Qt::AlignLeft);

    hBoxLayout->addSpacing(MASTHEAD_CENTER_WIDTH);


}

void MastheadCenter::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QWidget::paintEvent(event);
}
