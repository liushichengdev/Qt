#include <QApplication >
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window= new QWidget;

    window->setWindowTitle("My App");


    QPushButton *button1=new QPushButton("one");
    QPushButton *button2=new QPushButton("two");
    QPushButton *button3=new QPushButton("three");
    QPushButton *button4=new QPushButton("four");
    QPushButton *button5=new QPushButton("five");
    QPushButton *button6=new QPushButton("six");

    QHBoxLayout *horizontalLayout=new QHBoxLayout;
    horizontalLayout->addWidget(button1);
    horizontalLayout->addWidget(button2);
    horizontalLayout->addWidget(button3);

    QVBoxLayout *verticalLayout=new QVBoxLayout;

    verticalLayout->addWidget(button4);
    verticalLayout->addWidget(button5);
    verticalLayout->addWidget(button6);

    window->setLayout(verticalLayout);
    window->setLayout(horizontalLayout);

    window->show();

    return a.exec();
}
