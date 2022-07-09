#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    ui->tableWidget=new QTableWidget(12,3,this);

    //drag and drop
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setDragEnabled(true);
    ui->tableWidget->viewport()->setAcceptDrops(true);
    ui->tableWidget->setDropIndicatorShown(true);

    QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
                                                         pow(0, 0+1)));
    ui->tableWidget->setItem(0, 0, newItem);

    QTableWidgetItem *valuesHeaderItem = new QTableWidgetItem(tr("Values"));
    ui->tableWidget->setHorizontalHeaderItem(0, valuesHeaderItem);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    const QList<QTableWidgetItem *> selected = ui->tableWidget->selectedItems();
    int number = 0;
    double total = 0;

    for (QTableWidgetItem *item : selected) {
        bool ok;
        double value = item->text().toDouble(&ok);

        if (ok && !item->text().isEmpty()) {
            total += value;
            number++;
        }
    }

    ui->label->setText(QString::number(total));
}


void Dialog::on_pushButton_2_clicked()
{
    QString text=ui->lineEdit->text();
    const QList<QTableWidgetItem *> found = ui->tableWidget->findItems(
                text, Qt::MatchWildcard);

    for (QTableWidgetItem *item : found) {
        item->setSelected(true);
        // Show the item->text(0) for each item.
    }
}

