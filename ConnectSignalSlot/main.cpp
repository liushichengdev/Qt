#include <QCoreApplication>
#include "counter.h"
#include "calculator.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Counter a, b;
    Calculator calc;

    qDebug()<<"connect a's signal to b's slot";
    QObject::connect(&a, &Counter::valueChanged,
                     &b, &Counter::setValue);


    a.setValue(12);     // a.value() == 12, b.value() == 12
    qDebug()<<"a.value:"<<a.value()<<"b.value: "<<b.value();
    b.setValue(48);     // a.value() == 12, b.value() == 48
    qDebug()<<"a.value:"<<a.value()<<"b.value: "<<b.value();

//    qDebug()<<"connect b's signal to a's slot";
//    QObject::connect(&b, &Counter::valueChanged,
//                     &a, &Counter::setValue);

//    a.setValue(5);
//    qDebug()<<"a.value:"<<a.value()<<"b.value: "<<b.value();
//    b.setValue(9);
//    qDebug()<<"a.value:"<<a.value()<<"b.value: "<<b.value();

    //
    QObject::connect(&a, &Counter::valueChanged, &calc, &Calculator::setValue1);
    QObject::connect(&b, &Counter::valueChanged, &calc, &Calculator::setValue2);
    QObject::connect(&calc, &Calculator::value1Changed, &calc, &Calculator::setSum);
    QObject::connect(&calc, &Calculator::value2Changed, &calc, &Calculator::setSum);

    a.setValue(9);     // a.value() == 12, b.value() == 12
    qDebug()<<"a.value:"<<a.value()<<"b.value: "<<b.value()<<calc.Value1()<<calc.Value2()<<"Sum" <<calc.Sum();
    b.setValue(10);     // a.value() == 12, b.value() == 48
    qDebug()<<"a.value:"<<a.value()<<"b.value: "<<b.value()<<calc.Value1()<<calc.Value2()<<"Sum" <<calc.Sum();

    return app.exec();
}
