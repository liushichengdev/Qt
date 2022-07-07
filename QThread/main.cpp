#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mThread1;
    MyThread mThread2;
    MyThread mThread3;

    mThread1.setObjectName("myThread1");
    mThread2.setObjectName("myThread2");
    mThread3.setObjectName("myThread3");

    mThread1.start(QThread::HighestPriority);
    mThread2.start();
    mThread3.start();



    return a.exec();
}
