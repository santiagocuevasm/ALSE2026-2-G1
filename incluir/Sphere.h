#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
private:
    double radius;

public:
    Sphere();
    Sphere(double r);

    double getRadius() const;
    void setRadius(double r);

    double getVolume() const;
    double getSurfaceArea() const;
};

#endif
