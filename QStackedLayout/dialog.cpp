#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QWidget *firstPageWidget = new QWidget(this);
    QWidget *secondPageWidget = new QWidget(this);
    QWidget *thirdPageWidget = new QWidget(this);

    QStackedLayout *stackedLayout = new QStackedLayout(this);
    stackedLayout->addWidget(firstPageWidget);
    stackedLayout->addWidget(secondPageWidget);
    stackedLayout->addWidget(thirdPageWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stackedLayout);
    setLayout(mainLayout);

    QComboBox *pageComboBox = new QComboBox(this);
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));
    pageComboBox->addItem(tr("Page 3"));
    pageComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    //connect(pageComboBox, &QComboBox::activated,stackedLayout, &QStackedLayout::setCurrentIndex);
    connect(pageComboBox, &QComboBox::activated,stackedLayout, [=](){
        stackedLayout->setCurrentIndex(pageComboBox->currentIndex());
        stackedLayout->currentWidget()->show();
    });
}

Dialog::~Dialog()
{
    delete ui;
}

