#ifndef SPHERE_H
#define SPHERE_H
#include "Shape3D.h"

class Sphere : public Shape3D {
private:
  float radius;

public:
  Sphere(float radius) : radius(radius) {}

  void CalculateVolume() override {

    SetVolume((4 * 3.14f * pow(radius, 3)) / 3);
  }
  void Scale(float mashtab) override {
    radius *= mashtab;
    CalculateVolume();
  }

  void ShowInfo() override {
    std::cout << "sfera radius " << radius << " volume  "
              << GetVolume() << std::endl;
  }

  std::string GetName() override { return "sfera"; }
};

#endif