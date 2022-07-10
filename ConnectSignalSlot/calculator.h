#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QDebug>

class Calculator : public QObject
{
    Q_OBJECT
public:
    explicit Calculator(QObject *parent = nullptr);

    int Sum() const { return m_sum; }
    int Value1() const{return m_value1;}
    int Value2() const{return m_value2;}

public slots:
    void setValue1(int value);
    void setValue2(int value);
    void setSum();

signals:
    void sumChanged();
    void value1Changed(int value);
    void value2Changed(int value);

private:
    int m_sum=0;
    int m_value1=0;
    int m_value2=0;


};

#endif // CALCULATOR_H
