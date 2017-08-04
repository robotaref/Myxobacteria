#include "envoriment.h"
#include "mass.h"
#include "spring.h"
#include "vector3d.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include "bacteria.h"
#define NumM 5

using namespace std;

void Envoriment::PeriodicBoundaryCondition(vector3d *r)
{
    while ( Lx/2 > r->x)
        r->x=r->x+Lx;
    while ( Lx/2 < r->x)
        r->x=r->x - Lx;

    while ( Ly/2 > r->y)
        r->y=r->y+Ly;
    while ( Ly/2 < r->y)
        r->y=r->y-Ly;

    while ( Lz/2 > r->z)
        r->z=r->z + Lz;
    while ( Lz/2 < r->z)
        r->z=r->z - Lz;
}

Envoriment::Envoriment()
{


}

Envoriment::Envoriment(double Lx, double Ly, double Lz, double mu, int num, double multiF, double MeanRevT)
{
    this->multiF=multiF-1;
    this->MeanRevT=MeanRevT;
    dt=pow(2,-5);
    this->Lx=Lx;
    this->Ly=Ly;
    this->Lz=Lz;
    this->t=0;
    this->mu=mu;
    int l=ceil(sqrt(num));
    for(int i=0;i<num;i++)
       // bList.push_back(new Bacteria((double)(rand()%1000)/1000.0*Lx ,(double)(rand()%1000)/1000.0*Ly ,(double)(rand()%1000)/1000*2*3.141590,2,10,this,i));
          bList.push_back(new Bacteria((i%(l))*Lx/l     -Lx/2        ,(i/l)*Lx/l          -Ly/2     ,(double)(rand()%1000)/1000*2*3.141590,2,5 ,this,i));

    //bList.push_back(new Bacteria(-4,-2,0,2,3,this));
}

void Envoriment::update()
{
    for(int i=0;i<this->bList.size();i++)
        bList[i]->Update(this->t);

    for(int i=0;i<this->bList.size();i++)
        bList[i]->Move();

//    WtoFile();
    this->t+=dt;


}

void Envoriment::WtoFile()
{
//    ofstream trajectory;
//    if(t==0)
//        trajectory.open("tr.xyz");
//    else
//        trajectory.open("tr.xyz",fstream::app);

//    trajectory << NumM <<endl;
//    trajectory << " nodes  "<<endl;
//    for(int j=0;j<NumM;j++)
    //        trajectory << "s"<<  setprecision(5)<< setw(20)<<mList[j]->r.x<< setw(20)<<mList[j]->r.y<< setw(20)<<mList[j]->r.z<<endl;
}

int Envoriment::Desnity()
{
    int c=0;
        for(int i=0;i<bList.size();i++){
                if(bList[i]->isPulled==1){

                    c++;
                }
        }

    return c;

}


















