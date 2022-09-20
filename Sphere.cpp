//
// Created by ragib1481 on 9/11/22.
//

#include "Sphere.h"

Vec3 Sphere::center() {
    return c;
}

Color Sphere::getColor() {
    return this->color;
}

float Sphere::radius() {
    return this->r;
}

float Sphere::getTotalLightIntensity(const std::vector<Light>& lights, Vec3 n) {
    float intensity = 0;
    for (auto light: lights) {
        Vec3 v = light.loc() - c ;
        v.normalize();
        intensity += max(v.dot(n), 0.0);
    }
    return intensity / (float)lights.size();
}

float Sphere::max(float a, float b) {
    if (a<b)
        return b;
    return a;
}

Color Sphere::getColor(float lightIntensity) {
    float b = color.getBlue();
    float g = color.getGreen();
    float r = color.getRed();
    b = b * lightIntensity;
    g = g * lightIntensity;
    r = r * lightIntensity;
    return Color(b, g, r);
}

Light::Light(Vec3 l, Color c) {
    this->l = l;
    this->color = c;
}

Light::Light() {
    Vec3 l(0,0,0);
    Color color(0, 0, 0);
    this->l = l;
    this->color = color;
}

Color Light::getColor() {
    return color;
}

Vec3 Light::loc() {
    return l;
}

