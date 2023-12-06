#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDomDocument>
#include "BaseStruct.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void LoadXmlConfigFile();

    void BuildFunctionNodeVector();

private:
    Ui::MainWindow *ui;

    QString fileStr;
    QFile *xmlConfigFile;
    QDomDocument *dom;

    std::vector<FunctionNode> functionNodes;

};
#endif // MAINWINDOW_H
