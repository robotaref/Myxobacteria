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
    timer=new QTimer();
    timer->start(10);

    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    timer->stop();
    QPainter p(this);
    e->update();
    for(int j=0;j<e->bList.size();j++){
        for(int i=0;i<e->bList[j]->mList.size()-1;i++){
            if(e->bList[j]->isPulled==0)
                p.setPen(QPen(Qt::blue));
            else
                p.setPen(QPen(Qt::red));

            vector3d rab=e->bList[j]->mList[i+1]->r-e->bList[j]->mList[i]->r;
            e->PeriodicBoundaryCondition(&rab);

            double x1=(e->bList[j]->mList[i]->r.x+e->Lx/2)*w/e->Lx;
            double y1=(e->bList[j]->mList[i]->r.y+e->Ly/2)*w/e->Ly;
            double x2=(e->bList[j]->mList[i]->r.x+rab.x+e->Lx/2)*w/e->Lx;
            double y2=(e->bList[j]->mList[i]->r.y+rab.y+e->Ly/2)*w/e->Ly;
            p.drawLine(x1,y1,x2,y2);

            x1=(e->bList[j]->mList[i+1]->r.x+e->Lx/2)*w/e->Lx;
            y1=(e->bList[j]->mList[i+1]->r.y+e->Ly/2)*w/e->Ly;
            x2=(e->bList[j]->mList[i+1]->r.x-rab.x+e->Lx/2)*w/e->Lx;
            y2=(e->bList[j]->mList[i+1]->r.y-rab.y+e->Ly/2)*w/e->Ly;

            p.drawLine(x1,y1,x2,y2);
        }
    }
    t++;
    timer->start(1);
}
