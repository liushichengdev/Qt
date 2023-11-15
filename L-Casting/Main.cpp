#include "l_casting.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    L_Casting w;
    //去除标题栏
    //w.setWindowFlags(Qt::CustomizeWindowHint);
    w.show();
    return a.exec();
}
