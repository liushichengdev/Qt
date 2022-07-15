#include <QApplication>
#include "MWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MWindow window;
    window.show();
    return a.exec();
}
