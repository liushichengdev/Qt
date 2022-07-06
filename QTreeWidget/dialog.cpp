#include "dialog.h"
#include "./ui_dialog.h"



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setHeaderLabels(QStringList()<<"one"<<"two");
    AddRoot("1 Hello", "World");
    AddRoot("2 Hello", "World");
    AddRoot("3 Hello", "World");
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *item=new QTreeWidgetItem(ui->treeWidget);

    item->setText(0,name);
    item->setText(1,Description);
    ui->treeWidget->addTopLevelItem(item);

    AddChild(item,"one","Hello");
    AddChild(item,"two","Hello");
}

void Dialog::AddChild(QTreeWidgetItem *parent, QString name, QString Description)
{
    QTreeWidgetItem *item=new QTreeWidgetItem();

    item->setText(0,name);
    item->setText(1,Description);

    parent->addChild(item);
}

void Dialog::on_pushButton_clicked()
{
    ui->treeWidget->currentItem()->setBackground(0,Qt::red);
}

