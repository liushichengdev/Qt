#include "basedockwidget.h"
#include <QStyle>
#include <QHBoxLayout>
#include <QDesktopServices>
#include <QButtonGroup>

BaseDockWidget::BaseDockWidget()
{


    QIcon floatIcon(style()->standardPixmap(QStyle::SP_TitleBarNormalButton));
    m_pButtonFloating=new QPushButton(floatIcon,"", this);
    m_pButtonFloating->setStyleSheet("background-color: rgb(250,250,250);border:none;");
    //m_pButtonFloating->setFixedSize(QSize(Qt::BUTTON_WIDTH,BUTTON_HEIGHT));
    m_pButtonFloating->setToolTip(QStringLiteral("浮动"));
    //QHBoxLayout *mylayout=new QHBoxLayout(this);
    //mylayout->addWidget(m_pButtonFloating);

    //mylayout->setContentsMargins(5,0,0,5);
    //mylayout->setSpacing(0);
    //this->setFixedHeight(30);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QWidget *widget=new QWidget(this);
    QButtonGroup *buttonGroup=new QButtonGroup(widget);
    buttonGroup->addButton(m_pButtonFloating);
    buttonGroup->addButton(m_pButtonMin);
    buttonGroup->addButton(m_pButtonMax);

    this->setTitleBarWidget(widget);
}

void BaseDockWidget::onButtonFloatingclicked()
{
    QDockWidget *dw=qobject_cast<QDockWidget*>(parentWidget());
    Q_ASSERT(dw!=0);

    if(!dw->isFloating()){
        dw->setFloating(true);

        dw->show();
    }
}
