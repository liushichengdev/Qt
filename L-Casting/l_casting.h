#ifndef L_CASTING_H
#define L_CASTING_H

#include "Masthead.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class L_Casting; }
QT_END_NAMESPACE

class L_Casting : public QMainWindow
{
    Q_OBJECT

public:
    L_Casting(QWidget *parent = nullptr);
    ~L_Casting();

private:
    Ui::L_Casting *ui;

    QDockWidget *topDockWidget;
    QDockWidget *leftDockWidget;
    Masthead *masthead;
};
#endif // L_CASTING_H
