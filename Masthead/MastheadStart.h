#ifndef MASTHEADSTART_H
#define MASTHEADSTART_H

#include "GuideButton.h"
#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QHBoxLayout>
#include <QLabel>

class MastheadStart : public QWidget
{
    Q_OBJECT
public:
    explicit MastheadStart(QWidget *parent = nullptr, QSize* size=new QSize(0,0));

    void setGuideButton(QPushButton *newGuideButton);

    GuideButton *getGuideButton() const;

signals:

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    QHBoxLayout *hBoxLayout;
    GuideButton *guideButton;
    QLabel *logo_render;



};

#endif // MASTHEADSTART_H
