#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape3D.h"
#include "Circle.h"

class Cylinder : public Shape3D {
private:
  Circle baseCircle;
  float height;

public:
  Cylinder(float radius, float height) : baseCircle(radius), height(height) {}

  void CalculateVolume() override {
    baseCircle.CalculateArea();
    SetVolume(baseCircle.GetArea() * height);
  }

  void Scale(float mashtab) override {
    baseCircle.Scale(mashtab);
    height *= mashtab;
    CalculateVolume();
  }

  void ShowInfo() override {
    std::cout << "cilinder s radiusom " << baseCircle.GetArea()
              << "Height:  " << height << "Volume:  " << GetVolume()
              << std::endl;
  }

  std::string GetName() override { return "cilinder"; }
};

#endif