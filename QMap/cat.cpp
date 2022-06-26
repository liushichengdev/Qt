#include "cat.h"

Cat::Cat(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<"Constrcuted";
}

Cat::~Cat()
{
    qInfo()<<this<<"Deconstrcuted";
}

QString Cat::name() const
{
    return m_name;
}

void Cat::SetName(const QString &name)
{
    m_name=name;
}

int Cat::age() const
{
    return m_age;
}

void Cat::SetAge(int age)
{
    m_age=age;
}
