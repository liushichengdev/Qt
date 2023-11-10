#include "QMyBattery.h"
//#include "./ui_QMyBattery.h"
#include <QPainter>

QMyBattery::QMyBattery(QWidget *parent)
    : QWidget(parent)
{
}

QMyBattery::~QMyBattery()
{
}

void QMyBattery::setPowerLevel(int pow)
{
    mPowerLevel=pow;
    emit powerLevelChanged(pow);
    repaint();
}

int QMyBattery::powerLevel()
{
    return mPowerLevel;
}

void QMyBattery::setWarnLevel(int warn)
{
    mWarnLevel=warn;
}

int QMyBattery::warnLevel()
{
    return mWarnLevel;
}

QSize QMyBattery::sizeHint()
{
    int H=this->height();
    int W=this->width();
    QSize size(W,H);
    return size;
}

void QMyBattery::paintEvent(QPaintEvent *event)
{
    //界面组件的绘制
    Q_UNUSED(event);

    QPainter painter(this);
    QRect rect(0, 0, width(), height());
    painter.setViewport(rect);
    painter.setWindow(0, 0, 140, 50);	//设置窗口大小，逻辑坐标
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    //绘制电池边框
    QPen pen;
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(mColorBack);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    rect.setRect(1, 1, 129, 48);
    painter.drawRect(rect);		//绘制电池边框
    brush.setColor(mColorBorder);
    painter.setBrush(brush);
    rect.setRect(130, 15, 10, 20);
    painter.drawRect(rect);		//画电池正极头

    //画电池柱
    if (mPowerLevel > mWarnLevel)
    {
        //正常颜色电量柱
        brush.setColor(mColorPower);
        pen.setColor(mColorPower);
    }
    else
    {
        //电量低电量柱
        brush.setColor(mColorWarning);
        pen.setColor(mColorWarning);
    }

    painter.setBrush(brush);
    painter.setPen(pen);
    if (mPowerLevel > 0)
    {
        rect.setRect(5, 5, mPowerLevel, 40);
        painter.drawRect(rect);		//画电池柱
    }

    //绘制电量百分比文字
    QFontMetrics textSize(this->font());
    QString powStr = QString::asprintf("%d%%", mPowerLevel);
    QRect textRect = textSize.boundingRect(powStr);		//得到字符串的Rect
    painter.setFont(this->font());
    pen.setColor(mColorBorder);
    painter.setPen(pen);
    painter.drawText(55 - textRect.width() / 2, 23 + textRect.height() / 2, powStr);
}

