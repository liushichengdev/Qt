#ifndef MASTHEAD_H
#define MASTHEAD_H

#include "MastheadStart.h"
#include <QWidget>
#include <QSize>

class Masthead : public QWidget
{
    Q_OBJECT
public:
    explicit Masthead(QWidget *parent = nullptr,QSize* size=new QSize(0,0));

signals:

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    MastheadStart *mastheadStart;

};

#endif // MASTHEAD_H
