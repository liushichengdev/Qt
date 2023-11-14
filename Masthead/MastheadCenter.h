#ifndef MASTHEADCENTER_H
#define MASTHEADCENTER_H

#include <QWidget>
#include <QSize>
#include <QHBoxLayout>

class MastheadCenter : public QWidget
{
    Q_OBJECT
public:
    explicit MastheadCenter(QWidget *parent = nullptr, QSize *size=new QSize(0,0));

signals:

protected:
   void paintEvent(QPaintEvent *event) override;


private:
    QHBoxLayout * hBoxLayout;



};

#endif // MASTHEADCENTER_H
