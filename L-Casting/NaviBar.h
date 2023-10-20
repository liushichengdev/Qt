#ifndef NAVIBAR_H
#define NAVIBAR_H

#include <QListWidget>
#include "NaviBarItem.h"

class NaviBar : public QListWidget
{
    Q_OBJECT
public:
    NaviBar(QWidget *parent=nullptr);
    void addNaviBarItem(const QString &label);
    void addNaviBarItem(NaviBarItem *item);

    ~NaviBar();


protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;


};

#endif // NAVIBAR_H
