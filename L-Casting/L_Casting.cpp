#include "l_casting.h"
#include "IconDef.h"
#include "CommonDef.h"
#include "LButton.h"
#include "NaviBar.h"
#include "./ui_l_casting.h"
#include <QToolBox>
#include <QTreeWidget>
#include <QButtonGroup>
#include <QListWidget>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>

L_Casting::L_Casting(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::L_Casting)
{
    ui->setupUi(this);

    // define QToolBox
//    QToolBox *toolBox=new QToolBox(ui->centralwidget);
//    toolBox->setFrameShadow(QFrame::Plain);
//    toolBox->setFrameShape(QFrame::NoFrame);
//    toolBox->setFixedWidth(NAVIBAR_FOLD_WIDTH);

//    // zero
//    QSize size;
//    size.setHeight(ICON_SIZE_HEIGHT);
//    size.setWidth(ICON_SIZE_WIDTH);
//    QIcon icon;
//    icon.addFile(ICON_APP_MANAGEMENT,size);
//    QWidget *emptyWidget=new QWidget();
//    toolBox->addItem(emptyWidget,icon,"");
//    emptyWidget->setFixedSize(0,0);

//    // first
//    QMenu *salesMenu=new QMenu("Sales",nullptr);
//    QMenu *contractMenu=new QMenu("Contract",nullptr);
//    salesMenu->addMenu(contractMenu);
//    contractMenu->addMenu(new QMenu("1"));
//    contractMenu->addMenu(new QMenu("2"));
//    contractMenu->addMenu(new QMenu("3"));
//    salesMenu->addMenu(new QMenu("销售详情"));

//    toolBox->addItem(salesMenu,QString("销售管理"));

//    // second
//    QTreeWidget *treeWidget = new QTreeWidget();
//    treeWidget->setColumnCount(1);
//    QList<QTreeWidgetItem *> items;
//    for (int i = 0; i < 10; ++i)
//        items.append(new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(QString("item: %1").arg(i))));
//    treeWidget->insertTopLevelItems(0, items);
//    toolBox->addItem(treeWidget,QString("生产计划"));

//    // third
//    icon.addFile(ICON_RAW_MATERIAL,size);
//    QWidget *widget=new QWidget();
//    toolBox->addItem(widget,icon,"原料管理");

//    LButton *button1 = new LButton("原料列表", widget);
//    //button1->setStyleSheet("QPushButton{border:0px}");
//    QPushButton *button2 = new QPushButton("原料入库", widget);
//    QPushButton *button3 = new QPushButton("原料出库", widget);

//    QVBoxLayout * vBoxLayout=new QVBoxLayout(widget);
//    vBoxLayout->addWidget(button1);
//    vBoxLayout->addWidget(button2);
//    vBoxLayout->addWidget(button3);

//    // fourth
//    QListWidget *listWidget= new QListWidget();
//    toolBox->addItem(listWidget,QString("生产管理"));
//    listWidget->addItem("铸造管理");
//    listWidget->addItem("粗加工");
//    listWidget->addItem("热处理");
//    listWidget->addItem("精加工");

//    toolBox->setCurrentIndex(3);

////    //Define QToolBar
////    QToolBar *toolBar=new QToolBar("ToolBar1",this);

////    toolBar->setAllowedAreas(Qt::ToolBarArea::RightToolBarArea);
////    toolBar->setOrientation(Qt::Orientation::Horizontal);
////    toolBar->addWidget(new QMenu("ToolBar",toolBar));
////    toolBar->show();

//    // QMenu

//    QMenu *menu_all=new QMenu("ALL",this);
//    menu_all->setToolTipsVisible(true);
//    menu_all->addMenu(new QMenu("First"));
//    menu_all->addMenu(new QMenu("Second"));
//    menu_all->addMenu(new QMenu("Third"));

    QHBoxLayout *hBoxLayout=new QHBoxLayout(this);
    ui->centralwidget->setLayout(hBoxLayout);
//    hBoxLayout->addWidget(toolBox);
//    hBoxLayout->addWidget(menu_all);

    // Navibar
    NaviBar *naviBar=new NaviBar();
    naviBar->addNaviBarItem("1");
    naviBar->addNaviBarItem("2");
    naviBar->addNaviBarItem("3");
    naviBar->addNaviBarItem("item");
    hBoxLayout->addWidget(naviBar);


}

L_Casting::~L_Casting()
{
    delete ui;
}

