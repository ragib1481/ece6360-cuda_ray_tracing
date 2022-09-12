//
// Created by ragib1481 on 9/11/22.
//
/*
 * This file declares the data-structure for the camera.
 * Constructor takes pixel numbers and distance of image plane from the
 * camera point. The constructor calculate ray for each pixel and stores
 * in the memory.
 */

#ifndef ASSIGNMENT1_CAMERA_H
#define ASSIGNMENT1_CAMERA_H
#include <vector>
#include "Vec3.h"
#include "Ray.h"
#include "Sphere.h"


class Camera {
    Vec3 cameraPoint;
    int numPixels;
    float distanceImagePlane;
    const float dr =  0.1;                            // distance between pixels
    std::vector<std::vector<Color>> pixels;
    std::vector<std::vector<Ray>> rays;

public:
    Camera (int numPixels, float distanceImagePlane);
    void render (const std::vector<Sphere>& spheres);
    void saveImage (const std::string& filename);
    void printRays();
};


#endif //ASSIGNMENT1_CAMERA_H
