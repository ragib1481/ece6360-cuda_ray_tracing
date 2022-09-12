//
// Created by ragib1481 on 9/11/22.
//

#ifndef ASSIGNMENT1_RAY_H
#define ASSIGNMENT1_RAY_H
#include "Vec3.h"
#include "Sphere.h"
#include <cmath>

class Ray {
    Vec3 p;
    Vec3 v;
public:
    Ray();
    Ray(Vec3 p, Vec3 v);
    bool intersects(Sphere sphere);
    void print();
};


#endif //ASSIGNMENT1_RAY_H
