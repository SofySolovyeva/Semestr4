#ifndef TRIANGLEPYRAMID_H
#define TRIANGLEPYRAMID_H

#include "Shape3D.h"
#include "Triangle.h"

class TriangularPyramid : public Shape3D {
private:
  Triangle baseTriangle;
  float height;

public:
  TriangularPyramid(float base, float height)
      : baseTriangle(base, height), height(height) {
        CalculateVolume();
      }

  void CalculateVolume() override {
    baseTriangle.CalculateArea();
    SetVolume((1.0f / 3.0f) * baseTriangle.GetArea() * height);
  }

  void Scale(float mashtab) override {
    baseTriangle.Scale(mashtab);
    height *= mashtab;
    CalculateVolume();
  }

  void ShowInfo() override {
    std::cout << "treugolnay piromida s osnovaniem " << baseTriangle.GetArea()
              << " s vusotoy " << height << " imeet obem  " << GetVolume()
              << std::endl;
  }

  std::string GetName() override { return "treugolnay piromida"; }
};

#endif