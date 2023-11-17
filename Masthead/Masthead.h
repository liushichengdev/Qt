#ifndef MASTHEAD_H
#define MASTHEAD_H

#include "MastheadStart.h"
#include "MastheadCenter.h"
#include "MastheadEnd.h"
#include <QWidget>
#include <QSize>

class Masthead : public QWidget
{
    Q_OBJECT
public:
    explicit Masthead(QWidget *parent = nullptr,QSize* size=new QSize(0,0));
    ~Masthead();

    MastheadStart *getMastheadStart() const;

signals:

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    MastheadStart *mastheadStart;
    MastheadCenter *mastheadCenter;
    MastheadEnd *mastheadEnd;

};

#endif // MASTHEAD_H
