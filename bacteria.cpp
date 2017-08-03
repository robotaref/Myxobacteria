#include "bacteria.h"
#include "envoriment.h"
#include "mass.h"
#include "spring.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
Bacteria::Bacteria()
{

}

Bacteria::Bacteria(double x, double y, double theta, double length, int num, Envoriment *e, int id)
{
    this->e=e;
    this->num=num;
    for(int i=0;i<num-1;i++){
        sList.push_back(new spring(length,1000,this));
    }

    for(int i=0;i<num;i++){
        vector3d r(x+length*i*cos(theta),y+length*i*sin(theta),0);
        vector3d v(0,0,0);
        mList.push_back(new mass(1,r,v,this,i));
        if(i<num-1)
            mList[i]->AddSpring(sList[ i ],-1);
        if(i>0)
            mList[i]->AddSpring(sList[i-1], 1);

    }
    this->ID=id;
    this->tetha=theta+3.1415;
    this->length=length;
}

void Bacteria::Update()
{
    vector3d zero(0,0,0);
    for(int i=0;i<this->num;i++)
        mList[i]->F=zero;

    for(int i=0;i<this->num;i++)
        mList[i]->FindF();
    tetha+=(double)(rand()%1000)/10000.0-.05;
    while(tetha<0)
        tetha+=3.14159*2;
    while(tetha>3.14159*2)
        tetha-=3.14159*2;

    vector3d pullFV(cos(tetha),sin(tetha),0);

    mList[0]->F=mList[0]->F+pullFV*(isPulled*(e->multiF-1)+1)*2*num;


}

void Bacteria::Move()
{
    for(int i=0;i<num;i++)
        mList[i]->Move(e->dt);
}
