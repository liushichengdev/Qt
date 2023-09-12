#include "MWindow.h"
#include <QPushButton>
#include <QToolButton>
#include <QHBoxLayout>

MWindow::MWindow(QWidget *parent)
    : QMainWindow{parent}
{

    setFixedSize(800,600);

    createMenus();

    createTooBars();

    createDockWidget();
    createDockWidget();
    createDockWidget();

    createStatusBar();

    QTabBar *tabBar=new QTabBar();
    tabBar->addTab(tr("TabBar"));

    QMdiSubWindow *centralWidget = new QMdiSubWindow(this);
    //centralWidget->showFullScreen();
    setCentralWidget(centralWidget);
    QTabWidget *tabWidget=new QTabWidget();
    tabWidget->addTab(new QTableWidget(),QString(tr("Table 1")));
    tabWidget->addTab(new QTableWidget(),QString(tr("Table 2")));
    setCentralWidget(tabWidget);
    //setCentralWidget(centralWidget);
    //centralWidget->setWidget(tabWidget);



}

void MWindow::createMenus()
{
    //QMenuBar *menuBar = new QMenuBar(this);
    menuBar()->setFixedSize(800,25);
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *newAct=new QAction(tr("New"),this);
    QAction *openAct=new QAction(tr("Open"),this);
    QAction *saveAct=new QAction(tr("Save"),this);
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);

    connect(openAct,&QAction::triggered,this,[=](){
        QTabWidget *tabWidget=new QTabWidget();
        tabWidget->addTab(new QTableWidget(),QString(tr("Table Open")));
        setCentralWidget(tabWidget);
    });
}

void MWindow::createTooBars()
{
    QToolBar *toolBar=this->addToolBar(tr("&Tools"));
    QAction *openAct=new QAction(tr("Open"),this);
    QAction *saveAct=new QAction(tr("Save"),this);
    toolBar->addAction(openAct);
    toolBar->addAction(saveAct);
    toolBar->setToolButtonStyle(Qt::ToolButtonFollowStyle);
    toolBar->setMovable(true);
    toolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::RightToolBarArea |Qt::BottomToolBarArea);

    connect(openAct,&QAction::triggered, this, &MWindow::createDockWidget);
}

void MWindow::createDockWidget()
{
    QDockWidget *dockWidget = new QDockWidget(this);

    dockWidget->setSizeIncrement(100,100);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea |
                                Qt::BottomDockWidgetArea);
    //dockWidget->setFloating(true);
    //dockWidget->setWidget(this);
    addDockWidget(Qt::TopDockWidgetArea, dockWidget);
    setDockOptions(QMainWindow::AllowTabbedDocks);
    dockWidget->setFloating(false);
    //tabPosition(Qt::TopDockWidgetArea);
    QListWidget *headingList=new QListWidget(dockWidget);
    dockWidget->setWidget(headingList);

    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);

//    QMenu *qMenu1=new QMenu(tr("Menu1"),dockWidget);
//    QMenu *qMenu2=new QMenu(tr("Menu2"),dockWidget);
//    QAction *newAct=new QAction(tr("New"),dockWidget);
//    qMenu1->addAction(newAct);

//    QMenuBar *qMenuBar=new QMenuBar(dockWidget);
//    qMenuBar->setCornerWidget(dockWidget,Qt::BottomRightCorner);
//    qMenuBar->setNativeMenuBar(true);
//    qMenuBar->addMenu(qMenu1);
//    qMenuBar->addMenu(qMenu2);

//    QPushButton *button1 = new QPushButton("&销售", dockWidget);
//    button->setMenu(qMenu1);
//    button->setMenu(qMenu2);
//    button1->menu();
//    button1->setText("&合同");
//    QPushButton *button2 = new QPushButton("&技术", dockWidget);
//    button2->menu();

//    QToolButton *qToolButton=new QToolButton(dockWidget);
//    qToolButton->setAutoRaise(true);
//    qToolButton->setMenu(qMenu1);
//    qToolButton->setText("&技术");

//    QPushButton *button1 = new QPushButton("One");
//    QPushButton *button2 = new QPushButton("Two");
//    QPushButton *button3 = new QPushButton("Three");
//    QPushButton *button4 = new QPushButton("Four");
//    QPushButton *button5 = new QPushButton("Five");

//    QHBoxLayout *layout = new QHBoxLayout(dockWidget);
//    layout->addWidget(button1);
//    layout->addWidget(button2);
//    layout->addWidget(button3);
//    layout->addWidget(button4);
//    layout->addWidget(button5);
}

void MWindow::createStatusBar()
{
    QStatusBar *statusBar=this->statusBar();
    statusBar->showMessage(tr("Ready"));
}


