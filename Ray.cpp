//
// Created by ragib1481 on 9/11/22.
//

#include "Ray.h"
#include <iostream>

Ray::Ray(Vec3 p, Vec3 v) {
    this->p = p;
    this->v = v - p;
    this->v.normalize();
}

Ray::Ray() {
    this->p = Vec3(0, 0, 0);
    this->v = Vec3(0, 0, 0);
}

bool Ray::intersects(Sphere sphere) {
    // float a = v.dot(v);
    float a = v.norm2();
    float b = v.dot(p - sphere.center());
    float r = sphere.radius();
    // float c = (p - sphere.center()).dot(p - sphere.center()) - r * r;
    float c = (p - sphere.center()).norm2() - r * r;
    if ((b * b - 4 * a * c) >= 0)
        return true;
    else
        return false;
}

void Ray::print() {
    v.print();
}
