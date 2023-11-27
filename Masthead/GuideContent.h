#ifndef GUIDECONTENT_H
#define GUIDECONTENT_H

#include "GuideContentItem.h"
#include <QWidget>
#include <QVBoxLayout>

class GuideContent : public QWidget
{
    Q_OBJECT
public:
    explicit GuideContent(QWidget *parent = nullptr);
    ~GuideContent();

    void addGuideContentItem(GuideContentItem *item);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVBoxLayout *vBoxLayout;

};

#endif // GUIDECONTENT_H
