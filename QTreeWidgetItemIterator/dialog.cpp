#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    treeWidget = new QTreeWidget(this);
    TreeWidgetLearn();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::TreeWidgetLearn()
{
    treeWidget->setColumnCount(2);
    QStringList qSList={"Column1", "Column2"};
    treeWidget->setHeaderLabels(qSList);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 5; ++i)
        items.append(new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(QString("item: %1").arg(i))));
    treeWidget->insertTopLevelItems(0, items);

    QTreeWidgetItem *cities = new QTreeWidgetItem(treeWidget);
    cities->setText(0, tr("Cities"));
    QTreeWidgetItem *osloItem = new QTreeWidgetItem(cities);
    osloItem->setText(0, tr("Oslo"));
    osloItem->setText(1, tr("Yes"));

    QTreeWidgetItem *planets = new QTreeWidgetItem(treeWidget, cities);
    planets->setText(0, tr("Planets"));
}


void Dialog::on_pushButton_clicked()
{
    ui->pushButton->setText("Clicked");
    //QTreeWidgetItemIterator
    QTreeWidgetItemIterator it(treeWidget);
    while (*it) {
        //if ((*it)->text(0) == "Oslo"){
            (*it)->setSelected(true);
            //Sleep(1000);
            (*it)->setText(1, "Iterated");
            (*it)->setBackground(1,Qt::red);
        //}
        ++it;
    }
}

