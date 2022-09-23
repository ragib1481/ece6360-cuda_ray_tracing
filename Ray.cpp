//
// Created by ragib1481 on 9/11/22.
//

#include "Ray.h"
#include <iostream>
#include <limits>

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
    float a = v.dot(v);
    float b = 2 * v.dot(p - sphere.center());
    float r = sphere.radius();
    float c = (p - sphere.center()).dot(p - sphere.center()) - r * r;
    if ((b * b - 4 * a * c) >= 0)
        return true;
    else
        return false;
}

void Ray::print() {
    v.print();
}

Vec3 Ray::normalAtIntersection(Sphere sphere) {
    float a = v.dot(v);
    float b = 2 * v.dot(p - sphere.center());
    float r = sphere.radius();
    float c = (p - sphere.center()).dot(p - sphere.center()) - r * r;

    // only take the point that is closer to the image plane
    float t = (-b - sqrt(b * b - 4 * a *c)) / (2 * a);
    Vec3 intersectionPoint = p + v * t;
    Vec3 normal = intersectionPoint - sphere.center();
    normal.normalize();
    return normal;
}

float Ray::distanceToPoint(Vec3 point) {
    Vec3 v = (this->p - this->v - point);
    return v.dot(v);
}

Vec3 Ray::getIntersectionPoint(Sphere sphere) {
    float a = v.dot(v);
    float b = 2 * v.dot(p - sphere.center());
    float r = sphere.radius();
    float c = (p - sphere.center()).dot(p - sphere.center()) - r * r;

    // only take the point that is closer to the image plane
    float t = (-b - sqrt(b * b - 4 * a *c)) / (2 * a);
    Vec3 intersectionPoint = p + v * t;
    return intersectionPoint;
}

void Ray::trace(const std::vector<Sphere> &spheres, const std::vector<Light> &lights, Color* pixel) {
    float minDist = std::numeric_limits<float>::infinity();
    float dist = 0.0;
    Color closestColor(1.0, 1.0, 1.0);

    for (auto sphere: spheres) {
        if (this->intersects(sphere)) {
            Vec3 intersectionPoint = this->getIntersectionPoint(sphere);
            dist = this->distanceToPoint(intersectionPoint);
            if (dist < minDist) {
                minDist = dist;

                // set initial light intensity
                Vec3 n = this->normalAtIntersection(sphere);

                // calculate contribution from each light
                float lightIntensity = sphere.getTotalLightIntensity(lights, n);

                // assign color
                closestColor = sphere.getColor(lightIntensity);
            }
        }
    }
    *pixel = closestColor;
}

