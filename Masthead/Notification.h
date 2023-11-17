#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QPushButton>
#include <QIcon>

class Notification : public QPushButton
{
    Q_OBJECT
public:
    explicit Notification(QWidget *parent = nullptr);

signals:

private:
    QIcon notificationIcon;

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // NOTIFICATION_H
