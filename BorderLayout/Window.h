#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT
public:
    Window();

signals:
private:
    QLabel *createLabel(const QString &text);

};

#endif // WINDOW_H
