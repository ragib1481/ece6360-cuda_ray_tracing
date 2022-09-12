//
// Created by ragib1481 on 9/11/22.
//

#ifndef ASSIGNMENT1_VEC3_H
#define ASSIGNMENT1_VEC3_H


class Vec3 {
    float x;
    float y;
    float z;

public:
    Vec3();
    Vec3(float x, float y, float z);
    Vec3 operator+ (const Vec3& vec);
    Vec3 operator-(const Vec3 &vec);
    Vec3 operator* (const Vec3& vec);
    Vec3 operator* (float c);
    Vec3 operator/ (const Vec3& vec);
    Vec3 operator/ (float c);
    float dot (const Vec3& vec);
    void print();

};



#endif //ASSIGNMENT1_VEC3_H
