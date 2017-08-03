#include "mass.h"
#include "spring.h"
#include <iostream>
#include "envoriment.h"
#include "bacteria.h"
using namespace std;


mass::mass(int Id){
    m=0;
    ID=Id;
}

mass::mass(double M, vector3d R, vector3d V, Bacteria *b, int id){
    m=M;
    r=R;
    v=V;
    this->b=b;
    ID=id;
}

int mass::MMM()
{
//    cout<<"HI"<<endl;
    return 1;
}

void mass::AddSpring(spring *ss,int st)
{
    SpringList.push_back(ss);
    SpringType.push_back(st);
    if(st==-1)
        ss->m[0]=this;
    if(st==1)
        ss->m[1]=this;

}

void mass::FindF()
{
    vector3d zero(0,0,0);

    if(this->ID==0){
        for(int i=0;i<this->b->mList.size();i++){
            b->mList[i]->F=zero;
        }
    }


    for(int i=0;i<SpringList.size();i++){
        F=F+SpringList[i]->getF()*SpringType[i];
    }

    F=F-this->v*this->b->e->mu;

    if(ID< b->num-2){
        vector3d r1=this->r                       - this->b->mList[this->ID+1]->r;
        vector3d r2=this->b->mList[this->ID+2]->r - this->b->mList[this->ID+1]->r;
        b->e->PeriodicBoundaryCondition(&r1);
        b->e->PeriodicBoundaryCondition(&r2);
        vector3d n =r1.cross(r2);
        double tta=((r1.norm())*(r2.norm()));
        if(tta<=1&&tta>=-1)
            tta=acos(tta);
        else if(tta<-1)
            tta=3.14159;
        else
            tta=0;
        vector3d angF=r1.cross(n);
        angF = angF.norm();
        vector3d angFt=n.cross(r2);
        angFt = angFt.norm();
        double ask=1000;
        this->F                =this->F                -angF *ask*(tta-3.1415)/r1.length(); // Normalized to nullify sum of torq
        this->b->mList[ID+1]->F=this->b->mList[ID+1]->F+angF *ask*(tta-3.1415)/r1.length(); // I do this to keep momentum conservation!
        this->b->mList[ID+1]->F=this->b->mList[ID+1]->F+angFt*ask*(tta-3.1415)/r2.length(); // I do this to keep momentum conservation!
        this->b->mList[ID+2]->F=this->b->mList[ID+2]->F-angFt*ask*(tta-3.1415)/r2.length();
    }
    if(this->ID==0)
        this->b->isPulled=0;
    for(int i=0;i<b->e->bList.size();i++){
        if(b->ID == b->e->bList[i]->ID)
            continue;
        for(int j=0;j<b->e->bList[i]->mList.size();j++){
            vector3d Rmm= this->r -b->e->bList[i]->mList[j]->r;
            b->e->PeriodicBoundaryCondition(&Rmm);
            double lmm=Rmm.length();

            if( lmm <5){
                b->isPulled=b->e->bList[i]->isPulled=1;

                if(lmm<=1)
                    lmm+=1;
                vector3d Fmm=Rmm.norm()*100/lmm/lmm;
                this->F=this->F+Fmm;
            }
        }
    }

}

void mass::Move(double dt)
{
    v=v+F*dt;
    r=r+v*dt;

    b->e->PeriodicBoundaryCondition(&r);
}
