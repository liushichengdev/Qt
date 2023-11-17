#ifndef GUIDEHEADER_H
#define GUIDEHEADER_H

#include "GuideButton.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class GuideHeader : public QWidget
{
    Q_OBJECT
public:
    explicit GuideHeader(QWidget *parent = nullptr);
    ~GuideHeader();

    GuideButton *getGuideButton() const;

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QHBoxLayout *hBoxLayout;
    GuideButton *guideButton;
    QLabel *logo_render;
};

#endif // GUIDEHEADER_H
