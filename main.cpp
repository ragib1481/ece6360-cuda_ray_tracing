#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "SceneFileReader.h"
#include "Camera.h"
#include "Sphere.h"


using namespace std;

int main() {
    Camera camera(1024, 1.5);
    SceneFileReader reader("./lights.txt", "./spheres.txt");

    vector<Sphere> spheres;
    vector<Light> lights;
    spheres = reader.getSpheres();
    lights = reader.getLights();
    camera.render(spheres, lights);
    camera.saveImage("./image.tga");

    return 0;
}
