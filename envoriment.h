#ifndef ENVORIMENT_H
#define ENVORIMENT_H
#include <vector>
class mass;
class spring;
class vector3d;
class Bacteria;
class Envoriment
{
public:
    void PeriodicBoundaryCondition(vector3d *r);
    double dt;
    std::vector<Bacteria*> bList;
    double t;
    Envoriment();
    double Lx, Ly, Lz;
    double mu;
    double multiF;
    Envoriment(double Lx, double Ly, double Lz,double mu,int num,double multiF);
    void update();
    void WtoFile();
    int Desnity();
};

#endif // ENVORIMENT_H
