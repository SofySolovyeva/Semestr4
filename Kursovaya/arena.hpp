#pragma once //чтобы файл вкючили только один раз

#include <memory> //Определяет класс, оператор и несколько шаблонов, позволяющих выделять и освобождать объекты
#include <iostream> //написание и вывод текта
#include <iomanip> //форматирование вывода

#include "predator.hpp" // подрубание файлов
#include "prey.hpp"


class Arena {
public:
	Arena();
	~Arena() = default; //деструктор, испоьзуемый по умолчанию

	bool isInBounds(const Point2D& point) const; //проверяем находится ли точка на поле
	const Point2D& getPreyPos() const { return prey->getPos(); } //возвращаем местоположение жертвы
	void play(); //начало игры, объявление функции. опишем ее потом

private:
	bool askForSide() const; //запрос о стороне
	int askForPreyMove() const; //просим жертву походить
	std::pair<int, int> askForPredatorMove() const; //просим хищника походить
	void display() const;

	bool prey_is_npc; //за жертву играет игра 
	const int w = 30; //ширина
	const int h = 30; //длина
	std::unique_ptr<Predator> predator; //указатель
	std::unique_ptr<Prey> prey; //указатель
};