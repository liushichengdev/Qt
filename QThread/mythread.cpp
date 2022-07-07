#include "mythread.h"

MyThread::MyThread()
{

}

void MyThread::run()
{
    qDebug()<<this->objectName()<<"Running";

    for(int i=0;i<100;i++){
        qDebug()<<this->objectName()<<i;
    }
}
