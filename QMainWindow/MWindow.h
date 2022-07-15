#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QStatusBar>
#include <QListWidget>
#include <QStyle>
#include <QMdiSubWindow>
#include <QTableWidget>

class MWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MWindow(QWidget *parent = nullptr);
    void createMenus();
    void createTooBars();
    void createDockWidget();
    void createStatusBar();

signals:




};

#endif // MWINDOW_H
