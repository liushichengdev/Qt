/**
 *  QMap
 *  key and value pairs
 *
 */

#include <QCoreApplication>
#include <QSharedPointer>
#include <QRandomGenerator>
#include <QMap>
#include "cat.h"

// --- Creating a QMap ---
typedef QMap<QString, QSharedPointer<Cat>> catMap;

catMap getCats()
{
    catMap cats;

    for(int i=0; i<5;i++){
        QSharedPointer<Cat> ptr(new Cat());
        ptr->SetAge(QRandomGenerator::global()->bounded(1,5));
        ptr->SetName("Unkown");

        cats.insert("pet"+QString::number(i),ptr);
    }

    return cats;
}

// --- Display a QMap
void display(catMap &cats){

    foreach(QString key, cats.keys()){
        QSharedPointer<Cat> ptr=cats.value(key);
        qInfo()<<key<< ptr->name() << ptr->age() << ptr.data();
    }
}



// --- Modifying an item
void modifyCat(catMap &cats, QString key)
{
    if(cats.contains(key)){
        qInfo()<<"Mofiying:"<<key;
        cats[key]->SetAge(99);
        cats[key]->SetName("lucky");
        display(cats);
    }
}

// --- adding and inserting
void addCat(catMap &cats){
    qInfo()<<"Adding and inserting";

    QSharedPointer<Cat> ptr(new Cat());
    ptr->SetAge(1000);
    ptr->SetName("Test Cat");

    cats.insert("test",ptr);
    //cats["test"]=ptr;
    display(cats);
}

// --- search for an item
void findCat(catMap &cats, QString key){

    qInfo()<<"Exists:"<<cats.contains(key);

    auto iter=cats.find(key);
    if(iter!=cats.end()){
        qInfo()<<iter.key()<<iter.value();
    }

    foreach(QSharedPointer<Cat> value, cats.values()){
        qInfo()<<value;
    }

    foreach(QString key, cats.keys()){
        qInfo()<<"Key:"<<key<<"Value:"<<cats.value(key);
    }
}

// --- Removing an item
void removeCat(catMap &cats, QString key)
{
    if(!cats.contains(key)){
        qWarning()<<"Cat not found";
        return;
    }

    cats.remove(key);
    display(cats);
}


// --- main ---
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // --- Intro
    QMap<QString, double> lucky;
    lucky.insert(QString("SHICHENG"),9999);
    qInfo()<< lucky;
    qInfo()<<"My Lucky Number:"<< lucky["SHICHENG"];

    // --- Creating a QMap
    catMap cats=getCats();
    qInfo()<<cats;


    // --- Display QMap
    display(cats);

    // --- Modify a QMap
    modifyCat(cats, "pet2");

    // --- Adding and inserting
    addCat(cats);

    // --- searching for an item
    findCat(cats, "test");


    // --- removing an item
    removeCat(cats, "test");

    // --- Cleanup
    qInfo()<<"Clearing";
    cats.clear();

    return a.exec();
}
