#pragma once //чтобы файл вкючили только один раз

#include <cstddef> //для работы с размерами
#include <cmath> //математика

using Dir = std::pair<int, int>; //для системы координат x y

class Point2D
{
public:
	Point2D(int x = 0, int y = 0) : x(x), y(y) {} //прием значений х y
	~Point2D() = default; //деструктор, испоьзуемый по умолчанию

	bool operator==(const Point2D& other) const;
	Point2D operator+(const Dir& dir) const; //объявление оператор+, перегрузка оператора + для добавления дир к поинт2 (принимает ссылку в качестве параметра)
	int distance(const Point2D& other) const; // расстояние между одним поитн2 и другим, возвращает инт расстояния
	float distanceReal(const Point2D& other) const; // расстояние между одним поитн2 и другим с плавающей точкой
	void move(const int x_diff, const int y_diff, const std::size_t velocity = 1); //перемещает в другое место по значениям x y, с параметром velocity - скорость по умолчанию 
	void move(const Dir& dir, const std::size_t velocity = 1); //перегрузка мува, передвигает по параметру дир
	const int X() const { return x; }
	const int Y() const { return y; }
	bool isTouching(const Point2D& other) const; // проверка касания

private:
	int x = 0;
	int y = 0;
};
