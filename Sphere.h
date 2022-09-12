//
// Created by ragib1481 on 9/11/22.
//

#ifndef ASSIGNMENT1_SPHERE_H
#define ASSIGNMENT1_SPHERE_H
#include "Vec3.h"

class Color {
    char r, g, b;
public:
    Color(): r(0), g(0), b(0) { };
    Color(char b, char g, char r): r(r), g(g), b(b) { };
    char getBlue() { return b;}
    char getRed() { return r;}
    char getGreen() { return g;}
};

class Sphere {
    Vec3 c;             // center of the sphere
    float r;            // radius of the sphere
    Color color;
public:
    Sphere(Vec3 c, float r, Color color) : c(c), r(r) , color(color){ };
    Vec3 center();
    Color getColor();
    float radius();
};


#endif //ASSIGNMENT1_SPHERE_H
