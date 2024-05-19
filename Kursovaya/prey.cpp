#include "prey.hpp" //включаем другой файл
#include "arena.hpp" //включаем другой файл

void Prey::move(const Dir& dir) //метод move класса жертва принимает объект `Dir` как параметрор 
{
	pos.move(dir); //вызывает метод `move` объекта `pos`
}

void Prey::moveAsNpc(const Arena& arena) //метод `moveAsNpc` класса `Prey`, который принимает объект `Arena` как параметр
{
	int rand_dir_idx = rand() % available_dirs.size(); // рандомое число в дир

    //цикл пока позиция `pos` плюс смещение в направлении находится за пределами арены, проверяя это с помощью `isInBounds` арены
	while (!arena.isInBounds(pos + available_dirs[rand_dir_idx])) { 
		rand_dir_idx = rand() % available_dirs.size(); //случайное значение дир для смены направления
	}
	pos.move(available_dirs[rand_dir_idx]);
    //когда нашли возможное направление, идет перемещение `pos` по направлению

}
