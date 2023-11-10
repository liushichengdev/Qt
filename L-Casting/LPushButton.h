#ifndef LPUSHBUTTON_H
#define LPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class LPushButton : public QPushButton
{
    Q_OBJECT
public:
    LPushButton(const QString &text, QWidget *parent = nullptr);
    ~LPushButton();



signals:
    void leaveEvent_1();
    void enterEvent_1();

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    //void paintEvent(QPaintEvent *event) override;
};

#endif // LPUSHBUTTON_H
