#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QFile>
#include <QDomDocument>
#include <QDebug>

using namespace  std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString currentDir = QCoreApplication::applicationDirPath();
    qDebug()<<"Current Dir: "<<currentDir;
    QString fileStr=currentDir+QString("config.xml");
    qDebug()<<"File String: "<<fileStr;
    QFile *file=new QFile("F:/Qt/Qt Widget/XMLParser/config.xml");
    //QFile *file=new QFile(fileStr);

    QDomDocument *doc=new QDomDocument();


    if (!file->open(QIODevice::ReadOnly)){
        qDebug()<<"Open File Success";
    }

    bool parseResult=doc->setContent(file);
    // check the result of QDomDocument::setContent()
    if (parseResult) {
        qDebug()<<"XML Parse Success. ";
        file->close();
    }
    else{
        qDebug()<<"XML Parse Error: ";
        file->close();
        //return;
    }

    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc->documentElement();

    QDomNode n = docElem.firstChild();

    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            qDebug() << qPrintable(e.tagName()) <<"="<<qPrintable(e.text()); // the node really is an element.
        }
        n = n.nextSibling();
    }

    n = docElem.firstChild();
    while(!n.isNull()){
        QDomElement e = n.toElement();
        QDomAttr a=e.attributeNode("id");
        if(!a.isNull() && !e.isNull()){
            qDebug()<<e.tagName() <<","<<qPrintable(a.value())<<","<<e.text();
        }
        n=n.nextSibling();
    }

    QDomNodeList nodes = doc->elementsByTagName("Name");
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode n = nodes.at(i);
        if(n.isElement())
        {
            qDebug() << n.toElement().tagName()
                     << " = "
                     <<  n.toElement().text();
        }
    }

    nodes = doc->elementsByTagName("Function");
    qDebug()<<"Tag Name [Function] Size: "<<nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode node = nodes.at(i);
        if(node.isElement())
        {
            QDomNodeList nodes=node.childNodes();
            qDebug()<<"SubFunction :"<<nodes.count();
            for(int j=0;j<nodes.count();j++){
                QDomNode n=nodes.at(j);
                qDebug()<<n.toElement().text();
            }
        }
    }

    qDebug()<<"End";
}

MainWindow::~MainWindow()
{
    delete ui;
}

