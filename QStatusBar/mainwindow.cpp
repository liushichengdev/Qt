#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    statusLabel= new QLabel(this);
    statusProgress=new QProgressBar(this);

    ui->statusbar->addPermanentWidget(statusLabel);
    ui->statusbar->addPermanentWidget(statusProgress,1);

    statusProgress->setTextVisible(false);
    statusLabel->setText("Hello");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionDo_Something_triggered()
{
    ui->statusbar->showMessage("Hello StatusBar");
    statusProgress->setValue(45);
}

