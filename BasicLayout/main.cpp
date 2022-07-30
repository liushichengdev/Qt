#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog dialog;
    #ifdef Q_OS_ANDROID
        dialog.showMaximized();
    #else
        dialog.show();
    #endif

    return a.exec();
}
