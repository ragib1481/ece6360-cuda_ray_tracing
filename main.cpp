#include <iostream>
#include <vector>
#include <chrono>

#include "SceneFileReader.h"
#include "Camera.h"
#include "Sphere.h"


using namespace std;
typedef std::chrono::high_resolution_clock timer;

int main() {
    Camera camera(1024, 1.5);
    SceneFileReader reader("./lights.txt", "./spheres.txt");

    // load data
    vector<Sphere> spheres;
    vector<Light> lights;
    spheres = reader.getSpheres();
    lights = reader.getLights();

    // main render call
    auto start = timer::now();
    camera.render(spheres, lights);
    auto end = timer::now();

    // save rendered image
    camera.saveImage("./image.tga");

    std::chrono::milliseconds t = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
    cout << "Elapsed time: " << t.count() << "ms" << endl;
    return 0;
}
