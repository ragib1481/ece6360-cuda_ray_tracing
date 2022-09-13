//
// Created by ragib1481 on 9/12/22.
//

#ifndef ASSIGNMENT1_VEC3_H
#define ASSIGNMENT1_VEC3_H
#include <iostream>

class Vec3 {
    float r[3];
public:
    Vec3();
    Vec3(float x, float y, float z);
    Vec3(const Vec3& vec);
    Vec3 operator+(const Vec3& vec);
    Vec3 operator+(float c);
    Vec3 operator-(const Vec3& vec);
    Vec3 operator-(float c);
    Vec3 operator*(const Vec3& vec);
    Vec3 operator*(float c);
    Vec3 operator/(const Vec3& vec);
    Vec3 operator/(float c);
    Vec3& operator=(const Vec3& vec);
    float dot(const Vec3& vec);
    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec);

};

#endif //ASSIGNMENT1_VEC3_H
