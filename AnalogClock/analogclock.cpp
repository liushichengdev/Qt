#include <QTime>
#include <QTimer>
#include <QPainter>
#include "analogclock.h"
#include "./ui_analogclock.h"

AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnalogClock)
{
    QTimer *timer=new QTimer(this);
    connect(timer, &QTimer::timeout,this,QOverload<>::of(&AnalogClock::update));
    timer->start(1000);

    setWindowTitle("Analog Clock");

    resize(200,200);

    //ui->setupUi(this);
}

AnalogClock::~AnalogClock()
{
    delete ui;
}

void AnalogClock::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

    static const QPoint secondHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -90)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(0, 98, 98, 191);

    int side = qMin(width(), height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    // draw the hour hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    QTime time = QTime::currentTime();

    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    // draw the minute hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    // draw the second hand
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

    painter.save();
    //painter.rotate(1.0 * (time.minute() + time.second() / 60.0));
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();

    painter.setPen(secondColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
}
