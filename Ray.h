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
    Vec3 normalAtIntersection(Sphere sphere);
    void trace(const std::vector<Sphere>& spheres, const std::vector<Light>& lights, Color* pixel);
    float distanceToPoint(Vec3 point);
    Vec3 getIntersectionPoint(Sphere sphere);
    void print();
};


#endif //ASSIGNMENT1_RAY_H
