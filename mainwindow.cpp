#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mass.h"
#include "bacteria.h"
MainWindow::MainWindow(Envoriment *e,int w,int h) :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,100,w,h);
    this->e= e;
    r=5;
    this->w=w;
    this->h=h;
    t=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter p(this);
    e->update();
    for(int j=0;j<e->bList.size();j++){
        for(int i=0;i<e->bList[j]->mList.size();i++){
            if(e->bList[j]->isPulled==0)
                p.setPen(QPen(Qt::blue));
            else
                p.setPen(QPen(Qt::red));

            p.drawEllipse((e->bList[j]->mList[i]->r.x+e->Lx/2)*w/e->Lx-r,(e->bList[j]->mList[i]->r.y+e->Ly/2)*h/e->Ly-r,2*r,2*r);
        }
    }
    t++;
}
