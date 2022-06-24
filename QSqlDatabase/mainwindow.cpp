#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setHidden("true");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_DatabaseConnection_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("learning");

    ui->tableView->setHidden("false");
    ui->tableView->show();

    if(db.open()){

        QMessageBox::information(this,"Connection","Database Connected Success");

        QSqlTableModel *tableModel= new QSqlTableModel(this);
        tableModel->setTable("emp");
        tableModel->select();

        ui->tableView->setModel(tableModel);

        db.close();

    }
    else{
        QMessageBox::information(this,"Not Connected","Database is not Connected");
    }
}

