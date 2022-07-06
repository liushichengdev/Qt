#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtGui>
#include <QtCore>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDo_Something_triggered();

private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
    QProgressBar *statusProgress;

};
#endif // MAINWINDOW_H
