#ifndef NAVIBARITEM_H
#define NAVIBARITEM_H


#include <QMenu>
#include "LPushButton.h"

class NaviBarItem : public QWidget
{
public:
    NaviBarItem(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~NaviBarItem();

    void AddNaviBarSubItem(const QString &label);

private:
    void setItemSize();
    QSize itemSize;

    QMenu *menu;
    LPushButton *lButton;

protected:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // NAVIBARITEM_H
