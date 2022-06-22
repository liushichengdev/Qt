/**
 * QString - Qts String class also touch on QChar
 *
 *
 *
*/


#include <QCoreApplication>
#include <iostream>

void test(QString data)
{
    qInfo()<<data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ----- Creating ------
    std::cout<<"--- Creating ----"<<std::endl;
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
    std::cout<<"--- Reading ---"<<std::endl;
    for(int i=0; i<line.length();i++){

        QChar c=line.at(i);
        qInfo()<<c;
    }


    // --- Comparing and searching ---
    std::cout<<"--- Comparing and searching ---"<<std::endl;
    qInfo()<< "Compare"<<line.compare("hello world",Qt::CaseSensitivity::CaseInsensitive);
    qInfo()<< "Compare"<<line.compare("hello world",Qt::CaseSensitivity::CaseSensitive);
    qInfo()<< "Starts"<<line.startsWith("hello",Qt::CaseSensitivity::CaseInsensitive);
    qInfo()<< "Starts"<<line.startsWith("hello",Qt::CaseSensitive);
    qInfo()<< "End"<<line.endsWith("world",Qt::CaseInsensitive);
    qInfo()<< "End"<<line.endsWith("world",Qt::CaseSensitive);
    qInfo()<<"Contains"<<line.contains("world",Qt::CaseInsensitive);
    qInfo()<<"Contains"<<line.contains("world");
    qInfo()<<"Index"<<line.indexOf("world",Qt::CaseSensitivity::CaseInsensitive);
    qInfo()<<"Index"<<line.indexOf("World");

    // ---- Modifying and parsing ---
    std::cout<<"--- Modifying and parsing ---"<<std::endl;
    //line.append("Tody Bob said \"Hello wife\" How are you?");
    line.append("\r\nHow are you?");
    qInfo()<<"Escape"<<line;

    line.append("\r\n<i>This<i> is HTML<br>");
    qInfo()<<"Html"<<line.toHtmlEscaped();

    line.replace("?","!");
    qInfo()<<"Replaced"<<line;

    qInfo()<<"Upper"<<line.toUpper();
    qInfo()<<"Lower"<<line.toLower();
    qInfo()<<"Mid"<<line.mid(3,5);

    QStringList list=line.split("\n");
    foreach(QString item,list){
        qInfo()<<"item"<<item.trimmed();
    }

    // --- conversion ----
    std::cout<<" ---- Conversion between std::string and Qstring---- "<<std::endl;
    std::cout<<"std "<<line.toStdString()<<std::endl;

    qInfo()<<"UTF8"<< line.toUtf8();
    qInfo()<<"Base64"<< line.toUtf8().toBase64();
    qInfo()<<"Hex"<<line.toUtf8().toHex();

    // --- Not a Object ---
    test(line);

    return a.exec();
}
