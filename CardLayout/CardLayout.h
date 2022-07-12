#ifndef CARDLAYOUT_H
#define CARDLAYOUT_H

#include <QLayout>

class CardLayout : public QLayout
{
public:
    CardLayout(int spacing): QLayout()
    { setSpacing(spacing); }

    CardLayout(int spacing, QWidget *parent): QLayout(parent)
    { setSpacing(spacing); }

    ~CardLayout();

    void addItem(QLayoutItem *item) override;

    QSize sizeHint() const override;

    QSize minimumSize() const override;

    int count() const override;

    QLayoutItem *itemAt(int) const override;

    QLayoutItem *takeAt(int) override;

    void setGeometry(const QRect &rect) override;

private:
    QList<QLayoutItem *> m_items;
};

#endif // CARDLAYOUT_H
