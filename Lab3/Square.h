#ifndef SQUARE_H
#define SQUARE_H
#include "Shape2D.h"

class Square : public Shape2D {
private:
  float side;

public:
  Square(float side) : side(side) { CalculateArea(); } 

  void CalculateArea() override { SetArea(side * side); }

  void Scale(float mashtab) override {
    side *= mashtab;
    CalculateArea();
  }

  void ShowInfo() override {
    std::cout << "kvadrat storona  " << side << " square " << GetArea()
              << std::endl;
  }

  std::string GetName() override { return "kvadrat"; }
};

#endif