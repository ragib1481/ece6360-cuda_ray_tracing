//
// Created by ragib1481 on 9/11/22.
//

#ifndef ASSIGNMENT1_SPHERE_H
#define ASSIGNMENT1_SPHERE_H

#include <vector>
#include "Vec3.h"

class Color {
    float r, g, b;
public:
    Color(): r(0.0), g(0.0), b(0.0) { };
    Color(float b, float g, float r): r(r), g(g), b(b) { };
    float getBlue() { return b;}
    float getRed() { return r;}
    float getGreen() { return g;}
};

class Sphere;

class Light {
    Vec3 l;
    Color color;
public:
    Light();
    Light(Vec3 l, Color color);
    Vec3 loc();
    Color getColor();
};

class Sphere {
    Vec3 c;             // center of the sphere
    float r;            // radius of the sphere
    Color color;
public:
    Sphere(Vec3 c, float r, Color color) : c(c), r(r) , color(color){ };
    Vec3 center();
    Color getColor();
    Color getColor(float lightIntensity);
    float getTotalLightIntensity(const std::vector<Light>& lights, Vec3 n);
    float max(float a, float b);
    float radius();
};


#endif //ASSIGNMENT1_SPHERE_H
