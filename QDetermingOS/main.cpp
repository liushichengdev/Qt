#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>


void compileTime()
{
#ifdef Q_OS_MACOS
    qDebug()<<"This is Mac";
#endif

#ifdef Q_OS_LINUX
    qDebug()<<"This is Linux";
#endif

#ifdef Q_OS_WIN
    qDebug()<<"This is Windows";


#ifdef Q_OS_WIN32
    qDebug()<<"This is Windows 32 bit";
#endif

#ifdef Q_OS_WIN64
    qDebug()<<"This is Windows 64 bit";
#endif
#endif
}

void runTime()
{
    QSysInfo info;
    qInfo()<<"PrettyProductName:"<<info.prettyProductName();
    qInfo()<<"ProductType:"<<info.productType();
    qInfo()<<"ProductVersion:"<<info.productVersion();
    qInfo()<<"MachineHostName:"<<info.machineHostName();
    qInfo()<<"MachineUniqueId:"<<info.machineUniqueId();
    qInfo()<<"CurrentCpuArchitecture:"<<info.currentCpuArchitecture();
    qInfo()<<"BuildCpuArchitecture:"<<info.buildCpuArchitecture();
    qInfo()<<"BuildAbi:"<<info.buildAbi();
    qInfo()<<"BigEndian:"<<info.BigEndian;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //--- At Compile Time
    compileTime();

    //--- At Run Time
    runTime();

    return a.exec();
}
