#ifndef NAVIBAR_H
#define NAVIBAR_H

#include <QWidget>
#include <QListWidget>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QDebug>
#include "NaviBarItem.h"

class NaviBar : public QWidget
{
    Q_OBJECT
public:
    NaviBar(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    void AddNaviBarItem(const QString &label);
    void AddNaviBarSubItem(NaviBarItem *naviItem,const QString &label);

    ~NaviBar();


protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    QListWidget *listWidget=new QListWidget();

};

#endif // NAVIBAR_H
