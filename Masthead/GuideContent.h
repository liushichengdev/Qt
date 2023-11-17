#ifndef GUIDECONTENT_H
#define GUIDECONTENT_H

#include <QWidget>

class GuideContent : public QWidget
{
    Q_OBJECT
public:
    explicit GuideContent(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // GUIDECONTENT_H
