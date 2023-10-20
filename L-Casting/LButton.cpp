#include "lbutton.h"
#include <QPainter>

LButton::LButton(const QString &text, QWidget *parent):QPushButton(parent)
{
    this->setStyleSheet("QPushButton{border:0px}");
    this->setText(text);
    this->setMouseTracking(true);
}

void LButton::enterEvent(QEnterEvent *event)
{
    //设置背景
    this->setStyleSheet("QPushButton{ background-color: rgba(255, 245, 238, 100%)}");

    // 使用 QPainter
    QPushButton::enterEvent(event);
}

void LButton::leaveEvent(QEvent *event)
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

LButton::~LButton()
{

}
