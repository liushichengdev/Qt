#include "MainWindow.h"
#include "LoadStyleSheet.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
    QApplication a(argc, argv);

    // 加载并设置 qss
    LoadStyleSheet loadStyleSheet;
    //loadStyleSheet.setAllStyle();

    MainWindow w;
    //w.showFullScreen();
    //w.showNormal();
    w.show();
    return a.exec();
}
