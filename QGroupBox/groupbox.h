#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>

class GroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit GroupBox(QWidget *parent = nullptr);

signals:

};

#endif // GROUPBOX_H
