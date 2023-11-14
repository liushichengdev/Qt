#ifndef SUBFUNCTIONBUTTON_H
#define SUBFUNCTIONBUTTON_H

#include <QPushButton>

class SubFunctionButton : public QPushButton
{
    Q_OBJECT
public:

    SubFunctionButton(const QString &text, QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

};

#endif // SUBFUNCTIONBUTTON_H
