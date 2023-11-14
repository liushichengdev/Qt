#include "CommonDef.h"
#include "SubFunctionButton.h"
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

SubFunctionButton::SubFunctionButton(const QString &text, QWidget *parent)
    :QPushButton{parent}
{

    this->setText(text);

    this->setFixedSize(SUBFUNCTION_BTN_SIZE,SUBFUNCTION_BTN_SIZE);

    //设置字体
    QFont font;
    font.setFamily(SUBFUNCITON_FONT_FAMILY);
    font.setPointSize(SUBFUNCTION_FONT_SIZE);
    font.setBold(SUBFUNCTION_FONT_BOLD);

    this->setFont(font);

    // 利用调色板，设置字体颜色
    QPalette palette;
    palette.setColor(QPalette::ButtonText, Qt::black); //设置字体颜色为darkGray
    this->setPalette(palette); //设置QFont的颜色

    // set style
    this->setStyleSheet("QPushButton {"
                        "border-color: lightGray;"
                        "border-style: solid;"
                        "border-width: 0.9px;"
                        "border-radius: 5px;"
                        "}");

}

void SubFunctionButton::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QPushButton::paintEvent(event);
}

void SubFunctionButton::enterEvent(QEvent *event)
{
    this->setStyleSheet("QPushButton {"
                        "background-color:lightgray;"
                        "border-color: lightGray;"
                        "border-style: solid;"
                        "border-width: 0.9px;"
                        "border-radius: 5px;"
                        "}");
    QPushButton::enterEvent(event);
}

void SubFunctionButton::leaveEvent(QEvent *event)
{
    this->setStyleSheet("QPushButton {"
                        //"background:transparency;"
                        "border-color: lightGray;"
                        "border-style: solid;"
                        "border-width: 0.9px;"
                        "border-radius: 5px;"
                        "}");
    QPushButton::leaveEvent(event);
}
