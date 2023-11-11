#ifndef MASTHEADSTART_H
#define MASTHEADSTART_H

#include "GuideButton.h"
#include <QWidget>
#include <QPushButton>
#include <QIcon>

class MastheadStart : public QWidget
{
    Q_OBJECT
public:
    explicit MastheadStart(QWidget *parent = nullptr, QSize* size=new QSize(0,0));

    void setGuideButton(QPushButton *newGuideButton);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    GuideButton *_guideButton;
    QWidget _logo_render;



};

#endif // MASTHEADSTART_H
