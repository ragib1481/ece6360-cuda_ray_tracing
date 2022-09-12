#include <iostream>
#include <vector>
#include "Camera.h"
#include "Sphere.h"


using namespace std;

int main() {
    Camera camera(1024, 10);
    vector<Sphere> spheres;
    Vec3 center (0, 1.5, 5.5);
    Color color (255, 0, 255);
    Sphere sphere(center, 5, color);
    spheres.push_back(sphere);

    Vec3 center2 (0, 0, 5.5);
    Color color2 (0, 255, 0);
    Sphere sphere2(center2, 5, color2);
    spheres.push_back(sphere2);

    camera.render(spheres);
    camera.saveImage("./image.tga");
    return 0;
}
