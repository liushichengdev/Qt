#ifndef GUIDEBUTTON_H
#define GUIDEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QSize>
#include <QPaintEvent>

class GuideButton : public QPushButton
{
    Q_OBJECT
public:
    GuideButton();
    GuideButton(QWidget *parent=nullptr,QSize *size=new QSize(0,0));

private:
    QIcon _guideIcon;

protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

};

#endif // GUIDEBUTTON_H
