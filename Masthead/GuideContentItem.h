#ifndef GUIDECONTENTITEM_H
#define GUIDECONTENTITEM_H


#include <QWidget>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class GuideContentItem : public QWidget
{
    Q_OBJECT
public:
    explicit GuideContentItem(QWidget *parent = nullptr);
    ~GuideContentItem();



signals:


protected:
    void paintEvent(QPaintEvent *event) override;
    void focusInEvent(QFocusEvent *e) override;
    void focusOutEvent(QFocusEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    QHBoxLayout *hBoxLayout;
    QIcon icon;
    QPushButton *iconButton;
    QLabel *textLabel;

};

#endif // GUIDECONTENTITEM_H
