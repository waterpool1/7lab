#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent* ) override;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPoint mclick;
    QPoint xysqr = QPoint(300,300);

private:
    Ui::MainWindow *ui;
    int size = 100;
    bool popal = false;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H
