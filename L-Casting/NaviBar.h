#ifndef NAVIBAR_H
#define NAVIBAR_H

#include <QDockWidget>
#include <QVBoxLayout>
#include <QMenu>
#include <QLabel>
#include "NaviBarItem.h"

class NaviBar : public QDockWidget
{
    Q_OBJECT
public:
    NaviBar(const QString &title, QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    NaviBar(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    void addNaviBarItem(const QString &label);
    void addNaviBarItem(QWidget *item);
    void addNaviBarItem(QWidget *item,int stretch = 0, Qt::Alignment alignment = Qt::Alignment());

    ~NaviBar();


protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    QWidget *widget=new QWidget(this);
    QVBoxLayout *vBoxLayout=new QVBoxLayout(widget);

};

#endif // NAVIBAR_H
