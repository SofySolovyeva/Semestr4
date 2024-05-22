#include "point2d.hpp"//подрубаем файл

bool Point2D::operator==(const Point2D& other) const { //перегружаем оператор сравнения (==)
	return x == other.x && y == other.y; //возвращает тру если х и у соответственно равны other
}

//определение перегруженного оператора сложения + для класса Point2D. Создается новый объект типа Point2D
Point2D Point2D::operator+(const Dir& dir) const
{
	Point2D res(*this); //создаем новый объект res класса Point2D, инициализирем его с помощью копии текущего объекта, на котором вызывается данный код (через указатель this). res имеет те же значения координат, что и текущий объект, являясь копией 
	res.move(dir); //двигаемся в направлении дир
	return res;
}

// определение метода определение метода distance
int Point2D::distance(const Point2D& other) const {
	return std::abs(x - other.x) + std::abs(y - other.y); //расстояние между текущим объектом и объектом
}

//определение метода distanceReal, который вычисляет евклидово расстояние между текущим объектом и объектом other
float Point2D::distanceReal(const Point2D& other) const
{
	return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));//расстояние между точками
}

// определение метода move, который перемещает текущий объект на заданное смещение(x_diff, y_diff) с определенной скоростью (velocity) 
void Point2D::move(const int x_diff, const int y_diff, const std::size_t velocity)
{
	//Перемещаем с помощью изменения координат x и y объекта в цикле
	for (std::size_t i = 0; i < velocity; ++i) {
		x += x_diff;
		y += y_diff;
	}
}

void Point2D::move(const Dir& dir, const std::size_t velocity) //Этот метод принимает константную ссылку на объект типа Dir и значение типа std::size_t (velocity).
{
	move(dir.first, dir.second, velocity);//вызывается другой метод move, который принимает три параметра: координаты по x, по y и скорость
	//Параметры координат x и y передаются из объекта dir
}

bool Point2D::isTouching(const Point2D& other) const //метод принимает константную ссылку на объект типа Point2D (other).
{
	//смотрим находится ли текущий объект  на расстоянии не более 1 по координате x и не более 1 по координате y от объекта other
	return std::abs(other.x - x) <= 1 && std::abs(other.y - y) <= 1;
	//Если true, значит объекты находятся достаточно близко друг к другу.
}