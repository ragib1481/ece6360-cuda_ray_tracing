#include <iostream>
#include <vector>
#include "Camera.h"
#include "Sphere.h"


using namespace std;

int main() {
    Camera camera(1024, 1.5);
    vector<Sphere> spheres;
    Vec3 center (0, 0, 12);
    Color color (0, 0, 255);
    Sphere sphere(center, 1, color);
    spheres.push_back(sphere);

    Vec3 center1 (3, 0, 10);
    Color color1 (0, 255, 0);
    Sphere sphere1(center1, 1, color1);
    spheres.push_back(sphere1);

    camera.render(spheres);
    camera.saveImage("./image.tga");
    return 0;
}
