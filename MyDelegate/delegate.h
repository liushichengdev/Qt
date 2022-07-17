#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>
#include <QObject>
#include <QModelIndex>
#include <QSize>
#include <QSpinBox>
#include <QStyleOptionViewItem>

class Delegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent =0);

    QWidget *createEidter(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditerData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // DELEGATE_H
