#include "inventory.h"

Inventory::Inventory(QObject *parent)
    : QObject{parent}
{
    load();

}

void Inventory::app()
{
    qInfo()<<"Available commands:";
    qInfo()<<"add <name> <qty>";
    qInfo()<<"remove <name> <qty>";
    qInfo()<<"search <name>";
    qInfo()<<"save";
    qInfo()<<"load";
    qInfo()<<"list";
    qInfo()<<"quit";

    QTextStream stream(stdin);

    while(true){
        qInfo()<<"Enter a command:";
        QString line=stream.readLine();

        QStringList list=line.split(" ");
        if(list.size()<=0 )break;

        QString command=list.at(0).toUpper();

        if(command=="QUIT"){
            //app.exit(0);
            break;
        }

        if(command=="LIST") this->list();
        if(command=="LOAD") this->load();
        if(command=="SAVE") this->save();

        if(command=="SEARCH") {
            if(list.size()<2){
                qWarning()<<"Not enough info";
                continue;
            }
            QString name=list.at(1);
            this->search(name);
        }

        if(command=="ADD" || command=="REMOVE"){
            if(list.size()<3){
                qWarning()<<"Not enough info";
                continue;
            }

            QString name=list.at(1);
            bool ok;
            int qty;
            qty=list.at(2).toInt(&ok);

            if(!ok){
                qWarning()<<"Invalid quantity!";
                continue;
            }

            if(command=="ADD") this->add(name,qty);
            if(command=="REMOVE") this->remove(name,qty);
        }
    }

    this->save();
    qInfo()<<"Complete";
}

void Inventory::add(QString name, int qty)
{
    if(m_items.contains(name)){
        m_items[name]+=qty;
    }
    else{
        m_items.insert(name,qty);
    }
    qInfo()<<"[ADD] "<<name<<" : "<<qty;
}

void Inventory::remove(QString name, int qty)
{
    if(m_items.contains(name)){
        m_items[name]-=qty;
        if(m_items[name]<0)m_items.remove(name);
        qInfo()<<"[ROMOVE] "<<name<<" : "<<qty;
    }
    else{
        qWarning()<<"No item of that name";
    }
}

void Inventory::list()
{
    qInfo()<<"Items:"<<m_items.size();

    foreach(QString key, m_items.keys()){
        qInfo()<<key<<" = "<<m_items.value(key);
    }
}

void Inventory::search(QString name)
{
    if(m_items.contains(name)){
        qInfo()<<"[FOUND] "<<name<<":"<<m_items[name];
    }
    else{
        qInfo()<<"Do not have "<<name;
    }
}

void Inventory::save()
{
    QFile file("inventory.txt");

    if(!file.open(QIODevice::WriteOnly)){
        qCritical()<<"Could not save file:"<<file.errorString();
        return;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_3);

    int len=m_items.size();
    stream<<len;

    qInfo()<<"Number of items to save"<<len;

    foreach(QString key, m_items.keys()){
        qInfo()<<"Saving:"<<key;
        stream<<key;
        stream<<m_items.value(key);
    }

    file.close();

    qInfo()<<"File saved";
}

void Inventory::load()
{
    QFile file("inventory.txt");

    if(!file.exists()){
        qWarning()<<"File does not exist!";
        return;
    }

    if(!file.open(QIODevice::ReadOnly)){
        qCritical()<<"Could not open file:"<<file.errorString();
        return;
    }

    QDataStream stream(&file);

    if(stream.version()!=QDataStream::Qt_6_3){
        qCritical()<<"Wrong data stream version!";
        file.close();
        return;
    }

    m_items.clear();

    int max;
    stream>>max;

    qInfo()<<"Number of items to load:"<<max;

    for(int i=0;i<max;i++){
        QString key;
        int qty;
        stream>>key;
        stream>>qty;
        m_items.insert(key,qty);
    }

    file.close();

    qInfo()<<"File loaded";
}
