#ifndef SPRING_H
#define SPRING_H
class vector3d;
class mass;
class Bacteria;
class Envoriment;
class spring
{
public:
    spring();
    spring(double l0,double k, Bacteria *b);
    double L0,K;
    double L;
    Bacteria *b;
    vector3d *r0,*r1;
    mass *m[2];
//    vector3d F;
    double getL();
    vector3d getF();
    void stretch(double dL);

    vector3d *getR0() const;

    vector3d *getR1() const;
};

#endif // SPRING_H
