/**
 * QString - Qts String class also touch on QChar
 *
 *
 *
*/


#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ----- Creating ------
    QString line("Hello World");
    qInfo()<< line;

    QString name;
    name="LIU SHICHENG";
    qInfo()<<name;

    int pos=504;
    int max=7439;
    QString status=QString("Processing file %1 of %2").arg(pos).arg(max);
    qInfo()<<status;

    // --- Reading each char ----
    for(int i=0; i<line.length();i++){

        QChar c=line.at(i);
        qInfo()<<c;
    }

    return a.exec();
}
