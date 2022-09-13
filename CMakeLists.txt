cmake_minimum_required(VERSION 3.23)
project(assignment1)

set(CMAKE_CXX_STANDARD 20)

configure_file(spheres.txt
        spheres.txt COPYONLY)

configure_file(lights.txt
        lights.txt COPYONLY)

add_executable(assignment1 main.cpp Vec3.cpp Vec3.h Camera.cpp Camera.h Ray.cpp Ray.h Sphere.cpp Sphere.h SceneFileReader.cpp SceneFileReader.h)