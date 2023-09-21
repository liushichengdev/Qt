#ifndef BASEDOCKWIDGET_H
#define BASEDOCKWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QPushButton>

class BaseDockWidget:public QDockWidget
{
    Q_OBJECT
public:
    BaseDockWidget();

private:
    QPushButton *m_pButtonFloating;
    QPushButton *m_pButtonMin;
    QPushButton *m_pButtonMax;

    void onButtonFloatingclicked();
};

#endif // BASEDOCKWIDGET_H
