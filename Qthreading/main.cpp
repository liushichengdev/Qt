/**
 *  Thread Example
 *  Create a QThread
 *  Move a class to it
 *  Can not have a parent
 *
 *
 */

#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    qInfo()<<"Starting"<<QThread::currentThread();
    qInfo()<<"Doing Stuff"<<QThread::currentThread();

    Worker *worker=new Worker(); // No parent

    QThread thread;

    thread.setObjectName("Worker thread");

    worker->moveToThread(&thread);
    QObject::connect(&thread,&QThread::started,worker, &Worker::run);

    thread.start();
    qInfo()<<"Doing stuff"<<QThread::currentThread();
    for(int i=0; i<10;i++){
        qInfo()<<"Working: "<<QString::number(i)<<QThread::currentThread();
        QThread::currentThread()->msleep(500);
    }

    qInfo()<<"Finished"<<QThread::currentThread();

    return a.exec();
}
