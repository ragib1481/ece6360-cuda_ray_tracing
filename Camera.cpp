//
// Created by ragib1481 on 9/11/22.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Camera.h"

Camera::Camera(int numPixels, float distanceImagePlane):
                    numPixels(numPixels), distanceImagePlane(distanceImagePlane){

    // initialize pixels to zero. to be filled up later in rendering.
    pixels.resize(numPixels);
    for (size_t i=0; i<pixels.size(); i++) {
        pixels[i].resize(numPixels);
        for (size_t j=0; j<pixels[i].size(); j++) {
            pixels[i][j] = Color(1.0, 1.0, 1.0);
        }
    }

    // initialize one ray for each pixel, with the value p(0,0,0) and v = (x, y, d) - p.
    const float dr = imgPlaneExtent * 2 / numPixels;
    rays.resize(numPixels);
    for (size_t x=0; x<rays.size(); x++) {
        rays[x].resize(numPixels);
        for (size_t y=0; y<rays[x].size(); y++){
            Vec3 v((x * dr - imgPlaneExtent), (y * dr - imgPlaneExtent), distanceImagePlane);
            rays[x][y] = Ray(cameraPoint, v);
        }
    }
}

void Camera::render(const std::vector<Sphere>& spheres, const std::vector<Light>& lights) {
    for (size_t i=0; i<rays.size(); i++) {
        for (size_t j=0; j<rays[i].size(); j++) {
            for (auto sphere: spheres) {
                if (rays[i][j].intersects(sphere)) {
                    // set initial light intensity
                    Vec3 n = rays[i][j].normalAtIntersection(sphere);

                    // calculate contribution from each light
                    float lightIntensity = sphere.getTotalLightIntensity(lights, n);

                    // assign color
                    pixels[i][j] = sphere.getColor(lightIntensity);
                }
            }
        }
    }
}

void Camera::saveImage(const std::string& filename) {

    char *bytes = new char[numPixels * numPixels * 3];
    float maxColor = 0.0;
    float b, g, r;
    for (size_t i=0; i<pixels.size(); i++) {
        for (size_t j = 0; j < pixels[i].size(); j++) {
            b = pixels[i][j].getBlue();
            g = pixels[i][j].getGreen();
            r = pixels[i][j].getRed();
            if (b > maxColor)
                maxColor = b;
            if (g > maxColor)
                maxColor = g;
            if (r > maxColor)
                maxColor = r;
        }
    }
    int k = 0;
    for (int i=0; i<numPixels; i++) {
        for (int j = 0; j < numPixels; j++) {
            bytes[k++] = (char)(255 * pixels[j][i].getBlue() / maxColor);
            bytes[k++] = (char)(255 * pixels[j][i].getGreen() / maxColor);
            bytes[k++] = (char)(255 * pixels[j][i].getRed() / maxColor);
        }
    }

    std::ofstream outfile;

    outfile.open(filename, std::ios::binary | std::ios::out);	// open a binary file
    outfile.put(0);	// id length (field 1)
    outfile.put(0);	// color map type (field 2)
    outfile.put(2);	// image_type (field 3)
    outfile.put(0); outfile.put(0);	// color map field entry index (field 4)
    outfile.put(0); outfile.put(0);	// color map length (field 4)
    outfile.put(0);	// color map entry size (field 4)
    outfile.put(0); outfile.put(0);	// x origin (field 5)
    outfile.put(0); outfile.put(0);	// y origin (field 5)
    outfile.write((char*)&numPixels, 2);	// image width (field 5)
    outfile.write((char*)&numPixels, 2);	// image height (field 5)
    outfile.put(24);	// pixel depth (field 5)
    outfile.put(0);	// image descriptor (field 5)
    outfile.write(bytes, numPixels * numPixels * 3);	// write the image data
    outfile.close();	// close the file

}