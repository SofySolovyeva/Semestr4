#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape2D.h"

class Circle : public Shape2D {
private:
  float radius;

public:
  Circle(float radius) : radius(radius) {}

  void CalculateArea() override { SetArea(3.14f * pow(radius, 2)); }

  void Scale(float mashtab) override {
    radius *= mashtab;
    CalculateArea();
  }

  void ShowInfo() override {
    std::cout << "okruznost s radiusom  " << radius << " ploshad " << GetArea()
              << std::endl;
  }

  std::string GetName() override { return "krug"; }
};

#endif