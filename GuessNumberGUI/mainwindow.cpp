#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize
    srand(time(NULL));

    //Generate (1-10)
    secretNumber=rand()%10+1;
    qDebug()<<"Secret Number generated : "<< QString::number(secretNumber);
    ui->startOverButton->setDisabled(true);
    ui->messageLabl->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_guessButton_clicked()
{
    guessNumber=ui->spinBox->value();
    qDebug()<<"The guess Number is: "<<QString::number(secretNumber);

    if(guessNumber==secretNumber){
        //Congratulations
        ui->messageLabl->setText("Congratulations, number is :"+ QString::number(secretNumber));

        //Disable the guess button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else{
        if(secretNumber>guessNumber){
            ui->messageLabl->setText("Number is lower than that");
        }
        else if(secretNumber<guessNumber){
            ui->messageLabl->setText("Number is higher than that");
        }
    }
}


void MainWindow::on_startOverButton_clicked()
{
    //Enable the guess button
    ui->guessButton->setDisabled(false);

    //Disable the start Over Button
    ui->startOverButton->setDisabled(true);

    //Put the spinbox back to 1;
    ui->spinBox->setValue(1);

    //Regenerate the random number;
    secretNumber=rand()%10+1;

    //Clear the message lable
    ui->messageLabl->setText("");
}

