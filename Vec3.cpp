//
// Created by ragib1481 on 9/11/22.
//

#include "Vec3.h"
#include <iostream>
#include <cmath>

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}

Vec3 Vec3::operator+(const Vec3 &vec) {
    Vec3 newVec(0, 0, 0);
    newVec.x = this->x + vec.x;
    newVec.y = this->y + vec.y;
    newVec.z = this->z + vec.z;
    return newVec;
}

Vec3 Vec3::operator-(const Vec3 &vec) {
    Vec3 newVec(0, 0, 0);
    newVec.x = this->x - vec.x;
    newVec.y = this->y - vec.y;
    newVec.z = this->z - vec.z;
    return newVec;
}

Vec3 Vec3::operator*(const Vec3 &vec) {
    Vec3 newVec(0, 0, 0);
    newVec.x = this->x * vec.x;
    newVec.y = this->y * vec.y;
    newVec.z = this->z * vec.z;
    return newVec;
}

Vec3 Vec3::operator/(const Vec3 &vec) {
    Vec3 newVec(0, 0, 0);
    newVec.x = this->x / vec.x;
    newVec.y = this->y / vec.y;
    newVec.z = this->z / vec.z;
    return newVec;
}

float Vec3::dot(const Vec3 &vec) {
    return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Vec3 Vec3::operator*(float c) {
    return Vec3(this->x * c , this->y * c, this->z * c);
}

Vec3 Vec3::operator/(float c) {
    return Vec3(this->x / c, this->x / c, this->z / c);
}

void Vec3::print() {
    //std::cout << "[" << this->x << "," << this->y << "," << this->z << "]";
    // printf("[%1.3f, %1.3f, %1.3f]", this->x, this->y, this->z);
    printf("[%1.2f, %1.2f, %1.2f]", this->x, this->y, this->z);
}

void Vec3::normalize() {
    float c = sqrt(x * x + y * y + z * z);
    if (c > 0.000001) {
        x = x / c;
        y = y / c;
        z = z / c;
    }
}

float Vec3::norm2() {
    return x * x + y * y + z * z;
}

