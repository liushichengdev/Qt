/*
 * QList
 *
 * QList is a templated container
 * QList is not a QObject
 * QList and QVector are the same thing
 * No more 2GB limit
 * Qlist will auto resize itself
 * QObjects and pointers need to be cleaned
 *
 */

#include <QCoreApplication>
#include <QRandomGenerator>
#include <QSharedPointer>
#include <iostream>
#include "test.h"

//--- Creating and adding data
QList<int> getNumbers()
{
    QList<int> list;

    //use the operator
    list<<300 <<400 <<500;

    int size=QRandomGenerator::global()->bounded(1,10);
    for(int i=0;i<size;i++){
        list.append(QRandomGenerator::global()->bounded(1,100));
    }

    return list;
}

void test_numbers(QList<int> &list)
{
    qInfo()<<list;

    qInfo()<<"Length"<<list.length();
    qInfo()<<"Count"<<list.count();
    qInfo()<<"Size"<<list.size();

    for(int i=0; i<list.length();i++){
        qInfo()<<i<<"="<<list.at(i)<<"or"<<list[i];
    }

    qInfo()<<"-------------------";
    foreach(int i,list){
        qInfo()<<i;
    }
}

// --- Modify exiting data
void test_modify(QList<int> &list)
{
    std::cout<<"-------------------------Direct modify\n"<<std::endl;
    //direct mod
    list[0]=1000;
    //list.at(0)=3000;

    for(int i=0;i<list.length();i++){
        qInfo()<<i<<"="<<list.at(i);
    }
    std::cout<<"-------------------------appending\n"<<std::endl;
    //appending
    list.append(99);
    list<<2000<<3000;
    for(int i=0;i<list.length();i++){
        qInfo()<<i<<"="<<list.at(i);
    }

    std::cout<<"-------------------------insert\n"<<std::endl;
    list.insert(0,55);
    list.insert(1,22);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    for(int i=0;i<list.length();i++){
        qInfo()<<i<<"="<<list.at(i);
    }

    std::cout<<"-------------------------remove\n"<<std::endl;
    qInfo()<<"length"<<list.length();
    list.removeAt(0);
    qInfo()<<"RemoveAt"<<list.length();
    list.removeOne(255);
    qInfo()<<"RemoveOne"<<list.length();
    list.removeAll(255);
    qInfo()<<"RemoveAll"<<list.length();
    list.remove(3,3);
    qInfo()<<"Remove"<<list.length();
}


//-----search ----
void test_search(QList<int> &list)
{
    int item=999;

    list.insert(0,item);
    list.insert(3,item);
    list.append(item);

    //First
    int fpos=list.indexOf(item);
    qInfo()<<"First"<<fpos;

    //last
    int lpos=list.lastIndexOf(item);
    qInfo()<<"Last"<<lpos;

    //All
    int pos=list.indexOf(item);
    do{
        qInfo()<<"At"<<pos;
        pos=list.indexOf(item,pos+1);
    }while(pos>-1);


    qInfo()<<"Contains"<<list.contains(item);
    //Get a slice
    QList<int> items=list.sliced(0,2);
    qInfo()<<list;
    qInfo()<<items;

}


// --- Memory consideration ---
void test_deleteall()
{
    QList<Test*> list;

    for(int i=0;i<5;i++){
        list.append(new Test());
    }

    qInfo()<<"Cleanup";
    qDeleteAll(list);
    qInfo()<<list.length();
    list.clear();
    qInfo()<<list.length();
}

void test_smart()
{
    QList<QSharedPointer<Test>> list;

    for(int i=0;i<5;i++){
        QSharedPointer<Test> item(new Test());
        list.append(item);
    }

    qInfo()<<"Remove first";
    list.removeFirst();
    qInfo()<<"Clear";
    list.clear();
    qInfo()<<list.length();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //--- Creating and adding data
    QList<int> list=getNumbers();
    test_numbers(list);
    test_modify(list);
    test_search(list);
    test_deleteall();
    test_smart();

    return a.exec();
}
