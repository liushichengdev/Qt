#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDockWidget>
#include <QToolButton>
#include <QButtonGroup>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Menu Bar
    //QMenuBar *menuBar = new QMenuBar(this);
    //menuBar->setVisible(true);

    //QMenu *fileMenu=this->menuBar()->addMenu(tr("&File"));
    //this->menuBar()->show();
    QMenu *menu1=new QMenu("Menu1");
    QMenu *menu2=new QMenu("Menu2");

//    menuBar->addMenu(menu1);
//    menuBar->addSeparator();
//    menuBar->addMenu(menu2);
    //if(this->menuBar()) delete this->menuBar();
    //Tool Bar
    //Central Widget
    if(this->centralWidget()) delete this->centralWidget();

    //Dock Widget
    //允许嵌套dockwidget
    this->setDockNestingEnabled(true);
    QDockWidget *dock_tool=new QDockWidget(tr("Tool"),this);
    QDockWidget *dock_browser=new QDockWidget(tr("Browser"),this);
    QDockWidget *dock_detail=new QDockWidget(tr("Detail"),this);

    //
    dock_tool->setAllowedAreas(Qt::TopDockWidgetArea);
    //dock_tool->setMinimumSize(QMainWindow::width()/2, 600);
    dock_browser->setAllowedAreas(Qt::TopDockWidgetArea);
    dock_detail->setAllowedAreas(Qt::TopDockWidgetArea);

    //
    dock_tool->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dock_browser->setFeatures(QDockWidget::DockWidgetFloatable);
    dock_detail->setFeatures(QDockWidget::DockWidgetFloatable);

    //
    this->addDockWidget(Qt::TopDockWidgetArea,dock_tool);
    this->addDockWidget(Qt::TopDockWidgetArea, dock_browser);
    this->addDockWidget(Qt::TopDockWidgetArea,dock_detail);

    //
    this->splitDockWidget(dock_tool,dock_browser,Qt::Horizontal);
    this->splitDockWidget(dock_browser,dock_detail,Qt::Horizontal);


    //
    QWidget *baseWidget=new QWidget(this);


    //
    QPushButton *toolButton1=new QPushButton(this);
    toolButton1->setText(QApplication::translate("Widget", "...1", nullptr));
    QPushButton *toolButton2=new QPushButton(this);
    toolButton2->setText(QApplication::translate("Widget", "...2", nullptr));
    QPushButton *toolButton3=new QPushButton(this);
    toolButton3->setText(QApplication::translate("Widget", "...3", nullptr));
    QPushButton *toolButton4=new QPushButton(this);
    toolButton4->setText("...4");
    //toolButton1->setGeometry(QRect(30, 70, 50, 50));
    //toolButton2->setGeometry(QRect(30, 70, 50, 50));
    //toolButton3->setGeometry(QRect(30, 70, 50, 50));
    QGroupBox *groupBox=new QGroupBox(this);
    QHBoxLayout *hlayout1=new QHBoxLayout(this);
    QHBoxLayout *hlayout2=new QHBoxLayout(this);
    hlayout1->addWidget(toolButton1);
    hlayout1->addWidget(toolButton2,2);
    hlayout1->addWidget(toolButton3,3);
    hlayout1->addWidget(toolButton4);
    //groupBox->setLayout(hlayout2);

    QVBoxLayout *vlayout=new QVBoxLayout(this);
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
    baseWidget->setLayout(vlayout);
    //dock_tool->setWidget(groupBox);
    dock_tool->setWidget(baseWidget);
    baseWidget->show();
    // Status Bar
    //if(this->statusBar()) this->statusBar()->setWindowTitle(tr("Status Bar"));
    //


    delete dock_tool->titleBarWidget();
    QWidget* emptyTitle=new QWidget();
    dock_tool->setTitleBarWidget(emptyTitle);



    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

