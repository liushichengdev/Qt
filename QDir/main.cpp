#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>


// --- Current folder
void test_current()
{
    qInfo()<<QDir::currentPath();

    QDir dir;
    qInfo()<<dir.absolutePath();

}

// --- Listing
void test_list(QString path, bool recursive=false)
{
    QDir root(path);
    if(!root.exists()){
        qWarning()<<"Path not found"<<path;
        return;
    }

    QFileInfoList list=root.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries);

    foreach(QFileInfo fileInfo, list){

        qInfo()<<"---------------------------------";
        qInfo()<<"Name:"<<fileInfo.fileName();
        qInfo()<<"Path:"<<fileInfo.filePath();
        qInfo()<<"Absolute:"<<fileInfo.absolutePath();
        qInfo()<<"Created:"<<fileInfo.birthTime().toString();
        qInfo()<<"Modified:"<<fileInfo.lastModified().toString();
        qInfo()<<"Size:"<<fileInfo.size();

        QString type="unkown";
        fileInfo.isDir()?type="Dir":type="File";
        qInfo()<<"Type:"<<type;

        if(recursive && fileInfo.isDir()) test_list(fileInfo.absolutePath());
    }
}

// --- Modifying
void test_modify(QDir root)
{
    if(root.exists("Test"))
    {
        qInfo()<<"Test folder already exists";
        return;
    }

    if(root.mkdir("test")){
        QDir dir("test");
        qInfo()<<"Created:"<<dir.absolutePath();

        if(root.rename("test","test2")){
            qInfo()<<"Renamed:"<<dir.absolutePath();
            qInfo()<<"Test:"<<dir.exists();

            if(root.exists("test2")){
                if(!root.rmdir("test2")){
                    qInfo()<<"Failed - could not remove the directory!";
                }
            }
        }
    }


}

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    test_current();

    test_list(QDir::currentPath(),true);

    test_modify(QDir::currentPath());

    return a.exec();
}
