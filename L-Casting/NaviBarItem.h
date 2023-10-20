#ifndef NAVIBARITEM_H
#define NAVIBARITEM_H


#include <QListWidgetItem>

class NaviBarItem : public QListWidgetItem
{
public:
    NaviBarItem(QListWidget *parent = nullptr, int type = Type);
    NaviBarItem(const QString &text, QListWidget *parent = nullptr, int type = Type);
    NaviBarItem(const QIcon &icon, const QString &text, QListWidget *parent = nullptr, int type = Type);
    ~NaviBarItem();

private:
    void setTextAlignment(Qt::Alignment alignment= Qt::AlignCenter);
    void setItemSize();
    QSize itemSize;

protected:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // NAVIBARITEM_H
