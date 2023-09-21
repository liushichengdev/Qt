#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QDockWidget *dock_Image;    // 图像窗口
    QDockWidget* dock_Tool;// 工具箱窗口
    QDockWidget* dock_Geom;// 几何变换窗口
    QDockWidget* dock_Gray;// 灰度变换窗口
    QDockWidget* dock_Enhance;// 图像增强窗口
    QDockWidget* dock_Morp;// 形态学处理窗口
    QDockWidget* dock_Color;// 颜色模型窗口
    QDockWidget* dock_Prop;// 属性窗口
    QDockWidget* dock_Output;// 输出窗口

};
#endif // MAINWINDOW_H
