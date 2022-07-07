#include "dialog.h"
#include "./ui_dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //info
    QMessageBox::information(this, "Title Here","Text Here");
}


void Dialog::on_pushButton_2_clicked()
{
    //question
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this, "Title Here",
                          "Do you like Linux",
                          QMessageBox::Yes|QMessageBox::No);

    if(reply==QMessageBox::Yes){
        QMessageBox::information(this, "Title Here","You like Linux");
    }
}


void Dialog::on_pushButton_3_clicked()
{
    //warning
    QMessageBox::warning(this, "Title Here","Text Here");

}


void Dialog::on_pushButton_4_clicked()
{
    //custom
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,
                          "My Title",
                          "My Text here",
                          QMessageBox::YesToAll | QMessageBox::Yes | QMessageBox::No | QMessageBox::NoToAll);
}

