#ifndef GUIDECONTENTITEM_H
#define GUIDECONTENTITEM_H


#include <QWidget>
#include <QIcon>
#include <QHBoxLayout>

class GuideContentItem : public QWidget
{
    Q_OBJECT
public:
    explicit GuideContentItem(QWidget *parent = nullptr);

signals:


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetIcon;
    QWidget *WidgetFunction;

    QIcon icon;

};

#endif // GUIDECONTENTITEM_H
