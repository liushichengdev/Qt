#ifndef MASTHEAD_H
#define MASTHEAD_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>

class Masthead : public QWidget
{
    Q_OBJECT
public:
    explicit Masthead(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *) override;

};

#endif // MASTHEAD_H
