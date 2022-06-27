#include <QCoreApplication>
#include <QList>
#include <QStorageInfo>


// --- Storage Details
void display(QStorageInfo &storage, QString title){

    qInfo()<<"---"<<title<<"---";
    qInfo()<<"Name:"<<storage.name();
    qInfo()<<"Display:"<<storage.displayName();
    qInfo()<<"Root:"<<storage.isRoot();
    qInfo()<<"Path:"<<storage.rootPath();
    qInfo()<<"Device:"<<storage.device();
    qInfo()<<"File System:"<<storage.fileSystemType();
    qInfo()<<"ReadOnly:"<<storage.isReadOnly();
    qInfo()<<"Ready:"<<storage.isReady();
    qInfo()<<"Size:"<<storage.bytesTotal()/1000/1000<<"MB";
    qInfo()<<"Avaiable:"<<storage.bytesAvailable()/1000/1000<<"MB";
    qInfo()<<"Free:"<<storage.bytesFree()/1000/1000<<"MB";
    qInfo()<<"--------------";
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // --- Getting the root (C:\)
    QStorageInfo root=QStorageInfo::root();

    // --- Display
    display(root, "root");

    // --- Mounted Devices
    QList<QStorageInfo> devices=QStorageInfo::mountedVolumes();

    foreach(QStorageInfo device, devices){
        display(device, device.name());
    }

    return a.exec();
}
