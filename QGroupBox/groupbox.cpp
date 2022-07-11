#include "groupbox.h"

GroupBox::GroupBox(QWidget *parent)
    : QWidget{parent}
{
    //QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
    QGroupBox *groupBox = new QGroupBox(this);

    QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
    QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
    QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));

    radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
}
