#include "MWindow.h"

MWindow::MWindow(QWidget *parent)
    : QMainWindow{parent}
{

    setFixedSize(800,600);

    createMenus();

    createTooBars();

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
    QDockWidget *dockWidget = new QDockWidget(tr("Dock Widget"),this);
    dockWidget->setSizeIncrement(100,100);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea |
                                Qt::BottomDockWidgetArea);
    //dockWidget->setFloating(true);
    //dockWidget->setWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    setDockOptions(QMainWindow::AllowTabbedDocks);
    //tabPosition(Qt::TopDockWidgetArea);
    QListWidget *headingList=new QListWidget(dockWidget);
    dockWidget->setWidget(headingList);
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
}

void MWindow::createStatusBar()
{
    QStatusBar *statusBar=this->statusBar();
    statusBar->showMessage(tr("Ready"));
}


