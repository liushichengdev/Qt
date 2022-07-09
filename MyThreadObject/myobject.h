#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);

    void DoSetUp(QThread &cThread);

signals:

public slots:
    void DoWork();
};

#endif // MYOBJECT_H
