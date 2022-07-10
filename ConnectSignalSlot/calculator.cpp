#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{

}

void Calculator::setValue1(int value)
{
    m_value1=value;
    emit value1Changed(value);
}

void Calculator::setValue2(int value)
{
    m_value2=value;
    emit value2Changed(value);
}

void Calculator::setSum()
{
    m_sum=m_value1+m_value2;
    emit sumChanged();
}
