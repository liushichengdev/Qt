/**
 *QStringView
 *
 *
 *
 **/

#include <QCoreApplication>

void readnameByCopy(QString name)//copy is slow
{
    name.insert(0,"Mr.");
    qInfo()<<"Changed"<<name;
}

void readnameByReference(QString &name)//reference
{
    name.insert(0,"Mr.");
    qInfo()<<"Changed"<<name;
}

void readonly(QStringView name)
{
    qInfo()<<"name"<<name.data()<<name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstname="SHICHENG";
    QString lastname="LIU";

    // --- Copy and modification issues
    readnameByCopy(firstname);
    qInfo()<<"Original"<<firstname;

    readnameByReference(firstname);
    qInfo()<<"Original"<<firstname;


    // ---- Read only, no copy ---
    qInfo()<<"name"<<firstname.data()<<firstname;
    readonly(firstname);

    // --- Basic parsing ---
    firstname=firstname.remove("Mr.");
    QString fullname=firstname+" "+ lastname;
    foreach(QStringView part, QStringView(fullname).split(QChar(' '))){
        qInfo()<<"part"<<part;
        //Data types can get a bit annoying
        if(part.startsWith(QStringView(firstname),Qt::CaseInsensitive)){
            qInfo()<<"~First name detected";
            readonly(QStringView(firstname.mid(1,3)));
        }
    }




    return a.exec();
}
