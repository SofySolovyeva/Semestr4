#pragma once //можно подрубить только один раз

#include "character.hpp" //включаем другой файл

class Arena; //объявляем арену без описания, опишем ее в другом файле
//объявляем класс хищник, созданный из класса персонаж (так что он наследует из него члены и атрибуты)
class Predator : public Character {
public:
	Predator(const Point2D& pos) : Character(pos, Predator::getAvailableDirs()) {};
//конструктор класса, параметор это константная ссылка на объект поз класса Point2D,инициализирует переменную поз класса персонаж с заданным параметром pos
//передает параметр pos и результат getAvailableDirs() в качестве аргументов конструктору родительского класса персонаж

	void move(const Dir& dir, const std::size_t length);
    //функции движения.параметры - сылка на объект Dir с именем dir и длинна
	void moveAsNpc(const Arena& arena);
    //объявление функции движения по арене

private:
	static std::vector<Dir> getAvailableDirs() {
		return {
			{0, 1}, {1, 0}, {0, -1}, {-1, 0}
		};
	}
    //функция принадлежащая классу возвращает вектор объектов Dir, куда можно сходить хищнику
};