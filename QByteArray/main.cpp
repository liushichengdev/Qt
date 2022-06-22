/*
 * QByteArray
 * Best Array Ever
 *
 */
#include <QCoreApplication>


void stats(QByteArray &data)
{
    qInfo()<<"Length"<<data.length()<<"Capacity"<<data.capacity();
    qInfo()<<data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //--- Create an array ---
    QByteArray stuff;
    qInfo()<<stuff;

    QByteArray data("Hello");
    qInfo()<<data;

    QByteArray buffer(10,'\t');
    qInfo()<<buffer;

    QByteArray person(QString("SHICHENG").toLocal8Bit());
    qInfo()<<person;

    // --- Sizing the array ----
    data.reserve(25); // data="Hello"
    stats(data);

    data.resize(10);
    stats(data);

    data.truncate(8);
    stats(data);

    data.clear();
    stats(data);

    // --- Modify the data ---
    data.resize(5);
    data.fill('\x02');
    stats(data);

    data.replace(0,1,QByteArray("Sweet"));
    stats(data);

    data.replace(0,99,QByteArray("Sweet"));
    stats(data);

    data.fill('*');
    data.insert(3,QByteArray("Hello World"));
    stats(data);

    data.append('!');
    stats(data);

    data.remove(0,3);
    stats(data);

    // --- Reading the data ---
    int first=data.indexOf('*');
    int last=data.lastIndexOf('*');
    qInfo()<<"Start"<<first<<"End"<<last;

    if(first>-1 && last>-1){
        qInfo()<<data.mid(first,(last-first)+1);
    }

    data.clear();
    data.append("SHICHENG LIU");

    for(int i=0;i<data.length();i++){
        qInfo()<<"At"<<data.at(i)<<"or"<<data[i];
    }

    foreach(char c, data){
        qInfo()<<"Char"<<c;
    }

    foreach(auto item, data.split(' ')){
        qInfo()<<"Item"<<item;
    }


    //--- Encoding the data ---
    qInfo()<<"Normal"<<data;
    qInfo()<<"Repeat"<<data.repeated(3);

    data.append(QByteArray("\t\r\n"));
    data.insert(0,QByteArray("       \t\t\t"));
    qInfo()<<"Noraml"<<data;
    qInfo()<<"Trimed" <<data.trimmed();
    qInfo()<<"Actual"<<data;
    data=data.trimmed();

    QByteArray hex=data.toHex();
    qInfo()<<"Hex"<<hex;
    QByteArray from_hex=QByteArray::fromHex(hex);
    qInfo()<<"From Hex"<<from_hex;

    QByteArray base64=data.toBase64();
    qInfo()<<"base64"<<hex;
    QByteArray from_base64=QByteArray::fromBase64(base64);
    qInfo()<<"From Base64"<<from_base64;


    return a.exec();
}
