#include "Sphere.h"
#include <cmath>

Sphere::Sphere() : radius(1.0) {}

Sphere::Sphere(double r) : radius(r > 0 ? r : 1.0) {}

double Sphere::getRadius() const { return radius; }

void Sphere::setRadius(double r) {
    if (r > 0) radius = r;
}

double Sphere::getVolume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

double Sphere::getSurfaceArea() const {
    return 4.0 * M_PI * std::pow(radius, 2);
}
