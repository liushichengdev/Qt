#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QPushButton>
#include <QThread>
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QTreeWidget *treeWidget;
    void TreeWidgetLearn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
