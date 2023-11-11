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

    // set geometry
    this->setGeometry(MASTHEAD_START_POS_X*size->width()/APP_WIDTH,
                      MASTHEAD_START_POS_Y*size->height()/APP_HEIGHT,
                      size->width()*MASTHEAD_START_WIDTH/APP_WIDTH,
                      size->height()*MASTHEAD_START_HEIGHT/APP_HEIGHT);

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
}

void MastheadStart::resizeEvent(QResizeEvent *event)
{
    // 获取当前屏幕的大小
    QScreen *screen=QApplication::primaryScreen();
    QSize screenSize = screen->size();

    qDebug()<<"ScreenSize - Width :"<<screenSize.width()<<" Height: "<<screenSize.height();

    // 获取窗口的默认大小
    QSize defaultSize = sizeHint();
    qDebug()<<"DefaultSize - Width :"<<defaultSize.width()<<" Height: "<<defaultSize.height();

    // 计算宽度缩放比例和高度缩放比例
    float widthScale = (float)screenSize.width() / (float)defaultSize.width();
    float heightScale = (float)screenSize.height() / (float)defaultSize.height();

    // 应用缩放比例到窗口大小和内容
    int newWidth = (int)(defaultSize.width() * widthScale);
    int newHeight = (int)(defaultSize.height() * heightScale);
    resize(newWidth, newHeight);

    // 窗口内容缩放
    setContentsMargins(0, 0, 0, 0); // 确保无边距
    QWidget::resizeEvent(event); // 调用父类的resizeEvent函数
}
