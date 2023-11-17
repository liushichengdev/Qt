#ifndef MASTHEADEND_H
#define MASTHEADEND_H

#include "Avatar.h"
#include "Notification.h"
#include <QWidget>
#include <QHBoxLayout>

class MastheadEnd : public QWidget
{
    Q_OBJECT
public:
    explicit MastheadEnd(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QHBoxLayout *hBoxLayout;
    Avatar *avatar;
    Notification *notification;

};

#endif // MASTHEADEND_H
