#include "LPushButton.h"
#include <QPainter>

LPushButton::LPushButton(const QString &text, QWidget *parent):QPushButton(parent)
{


    this->setText(text);
    this->setMouseTracking(true);
    this->setFlat(true);
    this->setStyleSheet("QPusButton{"
                        "border:0px;"
                        "border-color:rgb(255, 255, 255);"
                        "border-style: solid;"
                        "border-radius: 4px;"
                        "background-color: rgb(255, 255, 255);"
                        "text-align: left;}"
                        "QPushButton::menu-indicator{image:none;}");


}

void LPushButton::enterEvent(QEnterEvent *event)
{
    //设置背景
    this->setStyleSheet("QPushButton{ background-color: rgba(255, 245, 238, 100%)}");

    // 使用 QPainter
    QPushButton::enterEvent(event);
}

void LPushButton::leaveEvent(QEvent *event)
{
    //this->setStyleSheet("QPushButton{ background-color:DEFAULT}");
    this->setStyleSheet("QPushButton{border:0px}");
    QPushButton::leaveEvent(event);
}

//void LButton::paintEvent(QPaintEvent *event)
//{
//    QPainter p(this);
//    p.setPen(QColor("red")); //设置画笔颜色
//    p.drawRect(0,0,width(), height());//绘制边框
//}

LPushButton::~LPushButton()
{

}
