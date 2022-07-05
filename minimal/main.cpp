#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    QLabel *label=new QLabel("<h2>Hello</h2> <font color=red><i>World</i></font>");

    label->show();

    return app.exec();
}
