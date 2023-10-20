#ifndef LBUTTON_H
#define LBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class LButton : public QPushButton
{
    Q_OBJECT
public:
    LButton(const QString &text, QWidget *parent = nullptr);
    ~LButton();

signals:
    void leaveEvent_1();
    void enterEvent_1();

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    //void paintEvent(QPaintEvent *event) override;
};

#endif // LBUTTON_H
