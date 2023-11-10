#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSlider->setSliderPosition(ui->battery->powerLevel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->battery->setPowerLevel(value);
    QString str=QString("当前电量：")+QString::asprintf("%d %", value);
    ui->label->setText(str);
}
