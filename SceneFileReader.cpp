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
        b = 255.0 * b;
        g = 255.0 * g;
        r = 255.0 * r;
        Vec3 center(x, y, z);
        Color color((char)b, (char)g, (char)r);
        Sphere sphere(center, radius, color);
        spheres.push_back(sphere);
    }
    return spheres;
 }

