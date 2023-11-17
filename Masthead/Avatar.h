#ifndef AVATAR_H
#define AVATAR_H

#include <QPushButton>

class Avatar : public QPushButton
{
    Q_OBJECT
public:
    Avatar();
    Avatar(QWidget *parent=nullptr);

private:
    QIcon avatarIcon;
    QMenu *menu;

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // AVATAR_H
