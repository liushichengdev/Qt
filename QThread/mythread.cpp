#include "mythread.h"

MyThread::MyThread()
{

}

void MyThread::run()
{
    qDebug()<<this->objectName()<<"Running";

    for(int i=0;i<100;i++){
        QMutex mutex;
        mutex.lock();
        if(this->stop){
            break;
        }
        mutex.unlock();
        //this->sleep(1);
        qDebug()<<this->objectName()<<i;
    }
}
