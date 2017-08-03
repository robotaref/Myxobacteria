#ifndef MASS_H
#define MASS_H
#include <vector>
#include "vector3d.h"

using namespace std;
class Envoriment;
class vector3d;
class spring;
class Bacteria;
class mass{

public:

    vector3d r;
    vector3d v;
    vector3d F;
    Bacteria *b;

    double m;
    int ID;
    mass(int Id);
    mass(double M, vector3d R,vector3d V,Bacteria *b,int id);
    int MMM();
    vector<spring*> SpringList;
    vector<int> SpringType;
    void AddSpring(spring *ss,int st);
    void FindF();
    void Move(double dt);
};

#endif // MASS_H
