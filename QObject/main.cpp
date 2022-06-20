#include <QCoreApplication>
#include "test.h"
#include "cat.h"
#include <QDebug>


void test1(Cat &cat){
    qInfo()<<"Addr "<<&cat;
}

void test2(Cat *cat){
    qInfo()<<"Ptr "<<cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    // connect the signal and the slot
    QObject::connect(&test,&Test::close,&a,&QCoreApplication::quit,Qt::QueuedConnection);
    test.dostuff();;

    Cat kitty;
    kitty.setObjectName("kitty");
    Cat death;
    death.setObjectName("kitty");

    test1(kitty);
    test2(&kitty);

    test1(death);
    test2(&death);

    int value=a.exec();

    qInfo()<<"Exit value: "<<value;
    return value;
}
