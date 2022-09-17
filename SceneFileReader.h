//
// Created by ragib1481 on 9/12/22.
//

#ifndef ASSIGNMENT1_SCENEFILEREADER_H
#define ASSIGNMENT1_SCENEFILEREADER_H
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "Sphere.h"
#include "Vec3.h"

using namespace std;

class SceneFileReader {
    string lightFileName;
    string sphereFileName;
    vector<Sphere> spheres;

public:
    SceneFileReader(string lightFileName, string sphereFileName);
    vector<Sphere> getSpheres();
};


#endif //ASSIGNMENT1_SCENEFILEREADER_H
