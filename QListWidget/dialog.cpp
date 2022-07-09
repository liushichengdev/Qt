#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //ui->listWidget->addItem("Hello");

    for(int i=0;i<9;i++){
        ui->listWidget->addItem(QString::number(i)+" item here");
    }

    new QListWidgetItem(tr("Sycamore"), ui->listWidget);
    new QListWidgetItem(tr("Chestnut"), ui->listWidget);
    new QListWidgetItem(tr("Mahogany"), ui->listWidget);

    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText("NewItemText");
    ui->listWidget->insertItem(0, newItem);
    //newItem->setToolTip(toolTipText);
    //newItem->setStatusTip(toolTipText);
    //newItem->setWhatsThis(whatsThisText);

    //ui->listWidget->sortItems(Qt::AscendingOrder);
    //ui->listWidget->sortItems(Qt::DescendingOrder);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //ui->listWidget->currentItem()->setText("Fuzzy Bunny");
    QListWidgetItem *item=ui->listWidget->currentItem();
    //item->setText("<h2><i><font color=red>Fuzzy Bunnys of doom</font></i></h2>");
    item->setText("Selected");
    item->setBackground(Qt::red);
}

