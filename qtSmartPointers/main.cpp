/**
 * Qt memory management
 * QScopedPointer
 * QSharedPointer
 *
 * QT Smart pointers
 *
 * C++ STD Smart Pointers along with boost are there as well
*/

#include <QCoreApplication>
#include "test.h"


void testScope()
{
    QScopedPointer<Test> ptr(new Test());
    ptr->message("Hello");
    //Here
}

void finish(QSharedPointer<Test> ptr)
{
    ptr->message("Finished");
}

void work(QSharedPointer<Test> ptr)
{
    ptr->message("working");
}

void step(QSharedPointer<Test> ptr)
{
    ptr->message("Stepping");

    for(int i=0;i<3;i++){
        work(ptr);
    }

    finish(ptr);
}

void testShared(Test* test)
{
    QSharedPointer<Test> ptr(test);
    ptr->message("Starting");
    step(ptr);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testShared(new Test());

    //testScope();

    return a.exec();
}
