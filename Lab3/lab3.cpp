#include <iostream>
#include "Square.h"
#include "Triangle.h"
#include "TrianglePyramid.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Sphere.h"

void TestSquare(){
    Square square(3);
    square.ShowInfo();
    square.Scale(3);
    square.ShowInfo();
}

void TestTriangle(){
    Triangle triangle(5, 10);
    triangle.ShowInfo();
    triangle.Scale(2);
    triangle.ShowInfo();
}

void TestTrianglePyramid(){
    TriangularPyramid pyramid(3, 8);
    pyramid.ShowInfo();
    pyramid.Scale(3);
    pyramid.ShowInfo();
}

void TestCircle(){
    Circle circle(4);
    circle.ShowInfo();
    circle.Scale(3);
    circle.ShowInfo();
}

void TestCylinder(){
    Cylinder cylinder(2, 4);
    cylinder.ShowInfo();
    cylinder.Scale(3);
    cylinder.ShowInfo();

}
void TestSphere(){
    Sphere sphere(6);
    sphere.ShowInfo();
    sphere.Scale(3);
    sphere.ShowInfo();
}

int main() {
    
    TestSquare();
    TestTriangle();
    TestTrianglePyramid();
    TestCircle();
    TestCylinder();
    TestSphere();

    return 0;
}