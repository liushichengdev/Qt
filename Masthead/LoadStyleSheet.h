#ifndef LOADSTYLESHEET_H
#define LOADSTYLESHEET_H

#include <QObject>

class LoadStyleSheet : public QObject
{
    Q_OBJECT
public:
    explicit LoadStyleSheet(QObject *parent = nullptr);

    void setAllStyle();

private:
    QString getAllStyle(QStringList strListStyleFiles, QString strDirPath);

signals:

};

#endif // LOADSTYLESHEET_H
