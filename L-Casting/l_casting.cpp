#include "l_casting.h"
#include "./ui_l_casting.h"
#include <QToolBox>
#include <QTreeWidget>
#include <QToolBar>

L_Casting::L_Casting(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::L_Casting)
{
    ui->setupUi(this);

    QToolBox *toolBox=new QToolBox(ui->centralwidget);

    QMenu *salesMenu=new QMenu("Sales",nullptr);
    QMenu *contractMenu=new QMenu("Contract",nullptr);
    salesMenu->addMenu(contractMenu);



    toolBox->addItem(salesMenu,QString("销售管理"));

    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
        items.append(new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(QString("item: %1").arg(i))));
    treeWidget->insertTopLevelItems(0, items);
    toolBox->addItem(treeWidget,QString("生产管理"));



    toolBox->setCurrentIndex(0);

    QToolBar *toolBar=new QToolBar("ToolBar1",this);
    this->addToolBar(toolBar);

    toolBar->setAllowedAreas(Qt::ToolBarArea::RightToolBarArea);
    toolBar->setOrientation(Qt::Orientation::Horizontal);
    toolBar->addWidget(new QMenu("ToolBar",toolBar));
    toolBar->show();

}

L_Casting::~L_Casting()
{
    delete ui;
}

