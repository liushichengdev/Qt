#ifndef QMYBATTERY_H
#define QMYBATTERY_H

#pragma once

#include <QWidget>
#include <QColor>
#include <QSize>

QT_BEGIN_NAMESPACE
namespace Ui { class QMyBattery; }
QT_END_NAMESPACE

class QMyBattery : public QWidget
{
    Q_OBJECT

public:
    QMyBattery(QWidget *parent = nullptr);
    ~QMyBattery();

    void setPowerLevel(int pow);		//设置当前电量
    int powerLevel();
    void setWarnLevel(int warn);				//设置电量低阈值
    int warnLevel();
    QSize sizeHint();					//缺省大小

private:
    Ui::QMyBattery *ui;
    QColor mColorBack = Qt::white;		//背景颜色
    QColor mColorBorder = Qt::black;	//电池边框颜色
    QColor mColorPower = Qt::green;		//电池柱颜色
    QColor mColorWarning = Qt::red;		//电量短缺时的颜色
    int mPowerLevel = 60;				//电量0-100
    int mWarnLevel = 20;				//电量低警示阈值

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:
    void powerLevelChanged(int);


};
#endif // QMYBATTERY_H
