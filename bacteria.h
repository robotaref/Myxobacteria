#ifndef BACTERIA_H
#define BACTERIA_H
#include <math.h>
#include <vector>

using namespace std;

class mass;
class Envoriment;
class spring;

class Bacteria
{
public:
    vector<mass*> mList;
    vector<spring*> sList;
    Envoriment *e;
    Bacteria();
    int isPulled;
    int ID;
    int num;
    double tetha;
    double pullF;
    double length;
    Bacteria(double x, double y,double theta, double length, int num, Envoriment *e,int id);
    void Update();
    void Move();
};

#endif // BACTERIA_H
