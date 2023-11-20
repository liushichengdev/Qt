#ifndef GUIDEWRAPPER_H
#define GUIDEWRAPPER_H

#include "GuideHeader.h"
#include "GuideContent.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

class GuideWrapper : public QWidget
{
    Q_OBJECT
public:
    explicit GuideWrapper(QWidget *parent = nullptr);
    ~GuideWrapper();

    GuideHeader *getGuideHeader() const;

signals:


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;

    GuideHeader *guideHeader;
    GuideContent *guideContent;

};

#endif // GUIDEWRAPPER_H
