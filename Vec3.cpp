//
// Created by ragib1481 on 9/12/22.
//

#include "Vec3.h"

Vec3::Vec3() { r[0] = 0; r[1] = 0; r[2] = 0; }

Vec3::Vec3(float x, float y, float z) { r[0] = x; r[1] = y; r[2] = z; }

Vec3::Vec3(const Vec3 &vec) {
    r[0] = vec.r[0];
    r[1] = vec.r[1];
    r[2] = vec.r[2];
}

Vec3 Vec3::operator+(const Vec3 &vec) {
    return Vec3(r[0] + vec.r[0], r[1] + vec.r[1], r[2] + vec.r[2]);
}

Vec3 Vec3::operator+(float c) {
    return Vec3(r[0] + c, r[1] + c, r[2] + c);
}

Vec3 Vec3::operator-(const Vec3 &vec) {
    return Vec3(r[0] - vec.r[0], r[1] - vec.r[1], r[2] - vec.r[2]);
}

Vec3 Vec3::operator-(float c) {
    return Vec3(r[0] - c, r[1] - c, r[2] - c);
}

Vec3 Vec3::operator*(const Vec3 &vec) {
    return Vec3(r[0] * vec.r[0], r[1] * vec.r[1], r[2] * vec.r[2]);
}

Vec3 Vec3::operator*(float c) {
    return Vec3(r[0] * c, r[1] * c, r[2] * c);
}

Vec3 Vec3::operator/(const Vec3 &vec) {
    return Vec3(r[0] / vec.r[0], r[1] / vec.r[1], r[2] / vec.r[2]);
}

Vec3 Vec3::operator/(float c) {
    return Vec3(r[0] / c, r[1] / c, r[2] / c);
}

Vec3& Vec3::operator=(const Vec3 &vec) {
    r[0] = vec.r[0];
    r[1] = vec.r[1];
    r[2] = vec.r[2];
    return *this;
}

float Vec3::dot(const Vec3 &vec) {
    return r[0] * vec.r[0] + r[1] * vec.r[1] + r[2] * vec.r[2];
}

std::ostream &operator<<(std::ostream &os, const Vec3 &vec) {
    os << "(" << vec.r[0] << "," << vec.r[1] << "," << vec.r[2] << ")";
    return os;
}
