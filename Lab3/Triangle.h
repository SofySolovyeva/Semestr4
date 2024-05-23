#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape2D.h"

class Triangle : public Shape2D {
private:
  float base;
  float height;

public:
  Triangle(float base, float height) : base(base), height(height) {}

  void CalculateArea() override { SetArea(0.5 * base * height); }

  void Scale(float mashtab) override {
    base *= mashtab;
    height *= mashtab;
    CalculateArea();
  }

  void ShowInfo() override {
    std::cout << "treugolnik s osnovaniem  " << base << " Height  " << height << " Square " << GetArea() << std::endl;
  }

  std::string GetName() override { return "treugolnik"; }
};

#endif