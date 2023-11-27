#include "LoadStyleSheet.h"

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QDebug>

LoadStyleSheet::LoadStyleSheet(QObject *parent)
    : QObject{parent}
{

}

void LoadStyleSheet::setAllStyle()
{
    QString strDirPath = ":/qss/";
    QStringList strListStyleFiles = QDir(strDirPath).entryList(QDir::Files);
    //qDebug()<<strListStyleFiles;
    QString strStyle = getAllStyle(strListStyleFiles, strDirPath);
    qApp->setStyleSheet(strStyle);
}

QString LoadStyleSheet::getAllStyle(QStringList strListStyleFiles, QString strDirPath)
{
    if (!strDirPath.endsWith("/"))
    {
        strDirPath.append("/");
    }

    QString strStyle;
    for (const auto &strFileName : strListStyleFiles)
    {
        QFile fileRead(strDirPath + strFileName);
        if (fileRead.open(QFile::ReadOnly))
        {
            strStyle += fileRead.readAll();
        }
        fileRead.close();
    }

    return strStyle;

}

