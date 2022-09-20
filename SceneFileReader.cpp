//
// Created by ragib1481 on 9/12/22.
//

#include "SceneFileReader.h"

SceneFileReader::SceneFileReader(string lightFileName, string sphereFileName) {
    this->lightFileName = lightFileName;
    this->sphereFileName = sphereFileName;
}

vector<Sphere> SceneFileReader::getSpheres() {

    vector<Sphere> spheres;

    ifstream file(sphereFileName);
    string line;
    while (getline(file, line)) {
        istringstream in(line);
        float x, y, z, radius, b, g , r;
        in >> x >> y >> z >> radius>> b >> g >> r;
        Vec3 center(x, y, z);
        Color color(b, g, r);
        Sphere sphere(center, radius, color);
        spheres.push_back(sphere);
    }
    return spheres;
 }

vector<Light> SceneFileReader::getLights() {
    vector<Light> lights;

    ifstream file(lightFileName);
    string line;
    while (getline(file, line)) {
        istringstream in(line);
        float x, y, z, b, g , r;
        in >> x >> y >> z >> b >> g >> r;
        Vec3 center(x, y, z);
        Color color(b, g, r);
        Light light(center, color);
        lights.push_back(light);
    }
    return lights;
}

