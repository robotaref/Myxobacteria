#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "envoriment.h"
#include <QMainWindow>
#include <QtGui>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Envoriment *e,int w, int h);
    ~MainWindow();
    Envoriment *e;
    int r;
    int w,h;
    int t;
    QTimer *timer;
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
