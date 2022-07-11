#include <QApplication>
#include "groupbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GroupBox *gbox=new GroupBox();

    gbox->show();

    return a.exec();
}
