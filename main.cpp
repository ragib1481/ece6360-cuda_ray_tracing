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
    spheres = reader.getSpheres();

    camera.render(spheres);
    camera.saveImage("./image.tga");

    return 0;
}
