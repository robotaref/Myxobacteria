#include "spring.h"
#include "vector3d.h"
#include "mass.h"
#include <iostream>
#include <math.h>
#include "envoriment.h"
#include "bacteria.h"
using namespace std;
spring::spring()
{

}

spring::spring(double l0, double k, Bacteria *b)
{
    L0=l0;
    K=k;
    this->b=b;

}

vector3d *spring::getR1() const
{
    return &(this->m[1]->r);
}

vector3d *spring::getR0() const
{
    return &(this->m[0]->r);
}


double spring::getL()
{
    vector3d r;
    r=*this->getR1() - *this->getR0();
    while ( -b->e->Lx/2 > r.x)
        r.x=r.x+b->e->Lx;
    while ( b->e->Lx/2 < r.x)
        r.x=r.x - b->e->Lx;

    while ( -b->e->Ly/2 > r.y)
        r.y=r.y+b->e->Ly;
    while ( b->e->Ly/2 < r.y)
        r.y=r.y - b->e->Ly;

    while ( -b->e->Lz/2 > r.z)
        r.z=r.z + b->e->Lz;
    while ( b->e->Lz/2 < r.z)
        r.z=r.z - b->e->Lz;

    return r.length();
    
}

vector3d spring::getF()
{
    vector3d F,r;
    r=*this->getR0() - *this->getR1();
    while ( -b->e->Lx/2 > r.x)
        r.x=r.x+b->e->Lx;
    while ( b->e->Lx/2 < r.x)
        r.x=r.x - b->e->Lx;

    while ( -b->e->Ly/2 > r.y)
        r.y=r.y+b->e->Ly;
    while ( b->e->Ly/2 < r.y)
        r.y=r.y - b->e->Ly;

    while ( -b->e->Lz/2 > r.z)
        r.z=r.z + b->e->Lz;
    while ( b->e->Lz/2 < r.z)
        r.z=r.z - b->e->Lz;

    F=r;

    F=F.norm();
    F=F*(1*K*(getL()-L0));

    return F;

}

void spring::stretch(double dL)
{
    L0+=dL;

}
