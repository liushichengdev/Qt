#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QFile>
#include <QDomDocument>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LoadXmlConfigFile();
    BuildFunctionNodeVector();

    qDebug()<<"End";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadXmlConfigFile()
{
    this->xmlConfigFile = new QFile("F:/Qt/Qt Widget/XMLParser/config.xml");

    this->dom = new QDomDocument();


    if (!xmlConfigFile->open(QIODevice::ReadOnly)) {
        qDebug() << "Open File Success";
    }

    QDomDocument::ParseResult parseResult = this->dom->setContent(xmlConfigFile);
    // check the result of QDomDocument::setContent()
    if (parseResult) {
        qDebug() << "XML Parse Success. ";
        this->xmlConfigFile->close();
    }
    else {
        qDebug() << "XML Parse Error: ";
        this->xmlConfigFile->close();
        //return;
    }
}

void MainWindow::BuildFunctionNodeVector()
{
    int id = 0;
    QDomNodeList nodes = this->dom->elementsByTagName("Function");
    qDebug() << "Tag Name [Function] Size: " << nodes.count();
    for (int i = 0; i < nodes.count(); i++)
    {
        QDomNode node = nodes.at(i);

        // check attributes
        if (!node.hasAttributes()) {
            qDebug() << "Please Check Xml Config File.";
        }

        id++;

        QDomNamedNodeMap map = node.attributes();

        FunctionNode functionNode;;

        functionNode.id = id;
        functionNode.name= map.namedItem("name").nodeValue();

        if (node.isElement())
        {
            QDomNodeList ns = node.childNodes();
            qDebug() << "SubFunction :" << ns.count();

            int subID = 0;

            for (int j = 0; j < ns.count(); j++) {
                QDomNode n = ns.at(j);
                qDebug() << n.toElement().text();
                subID++;

                SubFunctionNode subFunctionNode;
                subFunctionNode.id = subID;
                subFunctionNode.name = n.toElement().elementsByTagName("Name").at(0).toElement().text();
                subFunctionNode.dll = n.toElement().elementsByTagName("DLL").at(0).toElement().text();
                functionNode.subFunctionVector.push_back(subFunctionNode);
            }
        }

        this->functionNodes.push_back(functionNode);
    }


}