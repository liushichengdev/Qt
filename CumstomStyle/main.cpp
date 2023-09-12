#include "CustomStyle.h"

#include <QApplication>
#include <QtWidgets>

class CustomStyle : public QProxyStyle
{
    Q_OBJECT

public:
    CustomStyle(const QWidget *widget);
    ~CustomStyle() {}

    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const override;
};

void CustomStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                                QPainter *painter, const QWidget *widget) const
{
    if (element == PE_IndicatorSpinUp || element == PE_IndicatorSpinDown) {
        QPolygon points(3);
        int x = option->rect.x();
        int y = option->rect.y();
        int w = option->rect.width() / 2;
        int h = option->rect.height() / 2;
        x += (option->rect.width() - w) / 2;
        y += (option->rect.height() - h) / 2;

        if (element == PE_IndicatorSpinUp) {
            points[0] = QPoint(x, y + h);
            points[1] = QPoint(x + w, y + h);
            points[2] = QPoint(x + w / 2, y);
        } else { // PE_SpinBoxDown
            points[0] = QPoint(x, y);
            points[1] = QPoint(x + w, y);
            points[2] = QPoint(x + w / 2, y + h);
        }

        if (option->state & State_Enabled) {
            painter->setPen(option->palette.mid().color());
            painter->setBrush(option->palette.buttonText());
        } else {
            painter->setPen(option->palette.buttonText().color());
            painter->setBrush(option->palette.mid());
        }
        painter->drawPolygon(points);
    } else {
        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    QSpinBox spinBox;
    spinBox.setStyle(new CustomStyle(spinBox));
    spinBox.show();
    return app.exec();
}
