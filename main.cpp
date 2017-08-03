#include "mainwindow.h"
#include <QApplication>
#include "envoriment.h"
#include <iostream>
#include <fstream>
#include <math.h>
#define steps 2000
#define frequency 20
#define change 1
using namespace std;
int TryNum=1;
double data[steps/frequency+1][change];
int main(int argc, char *argv[])
{
    for(int i=0;i<=steps/frequency;i++){
        for(int j=0;j<change;j++)
            data[i][0]=0;
    }
   // QApplication a(argc, argv);
    for(int wtc=0;wtc<change;wtc++){
        for(int tr=0;tr<TryNum;tr++){
            Envoriment *e=new Envoriment(200,200,20,1,100,4);

//            MainWindow w(e,500,500);
            int V=0;
            if(V==0){
                for(int t=0;t<=steps;t++){
                    e->update();
                    // e->DesnityToFile(t,10);
                    if(t%10==0){
                        data[t/frequency][wtc]+=e->Desnity()/TryNum;
                    }
                    if(t%100==0){
                        cout<<"On changing parameter "<<wtc+1<<" out of "<<change<<" trying for "<<tr+1<<" times out of ";
                        cout<<TryNum<<" on step "<<t<<" of "<<steps<<" steps"<<endl;
                    }
                }
            }
//            else{
//                QTimer *t=new QTimer();
//                t->start(1);
//                w.show();
//                MainWindow::connect(t,SIGNAL(timeout()),&w,SLOT(repaint()));
//            }
        }
    }


    ofstream file;
    file.open("output.txt");
    cout<<file.is_open()<<endl;
    for(int i=0;i<steps/frequency;i++){
        file<<i*frequency<<"\t";
        for(int j=0;j<change;j++)
            file<<data[i][j]/(j*10+1)<<"\t";
        file<<endl;
    }
    return 0;
}











