#pragma once //чтобы файл вкючили только один раз

#include <vector>

#include "point2d.hpp" //подрубили файл


class Character {
public:
	Character(const Point2D& pos, std::vector<std::pair<int, int>> available_dirs) : //конструктор класса символов
    //Point2D& pos - постоянная ссылка но объект класса поинт2 название объекта - поз
    //std::vector<std::pair<int, int>> available_dirs - вектор с парами чисел
    //инициализирует поз и доступные дирс
		pos(pos), available_dirs(available_dirs) {}

	virtual ~Character() = default; //деструктор класса по умолчанию
    // виртуал значит что это можно использовать в базовых классах для других дочерних классов

	const Point2D& getPos() const { return pos; } //функция поз возвращает значение поз (позиции) где мы и кто мы
	const std::vector<Dir>& getAvailableDirsMember() const { return available_dirs; } //функция getAvailableDirsMember возвращает куда можно пойти ещё (например нельзя пойти в стену)

protected: //все что тут доступно для класса и его дочерним классам
	Point2D pos{}; //объявляет переменную позицию персонажа
	const std::vector<Dir> available_dirs; //объявлет вектор куда может двигаться персонаж
};