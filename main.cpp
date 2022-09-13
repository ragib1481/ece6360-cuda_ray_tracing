#include <iostream>
#include <vector>
#include "Camera.h"
#include "Sphere.h"


using namespace std;

int main() {
    Camera camera(2048, 2);
    vector<Sphere> spheres;
    Vec3 center (0, 0, 5.5);
    Color color (0, 0, 255);
    Sphere sphere(center, 4.8, color);
    spheres.push_back(sphere);

    camera.render(spheres);
    camera.saveImage("./image.tga");
    return 0;
}
