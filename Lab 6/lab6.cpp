#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

int main() {
    std::ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        std::cout << "Ne rabotaet" << std::endl;
        return 1;
    }

    std::vector<int> vector;
    int nu;
    while (inputFile >> nu) {
        vector.push_back(nu);
    }

    std::reverse(vector.begin(), vector.end()); // Реверсируем

    int min = *std::min_element(vector.begin(), vector.end()); // Находим минимальный элемент
    std::cout << "Minimum: " << min << std::endl;

    vector.erase(std::remove_if(vector.begin(), vector.end(), [](int n){ return n % 2 == 0; }), vector.end()); // Удаляем четные элементы

    std::sort(vector.begin(), vector.end()); // Сортировка по возрастанию

    vector.insert(std::upper_bound(vector.begin(), vector.end(), 46), 46); // Вставляем произвольный элемент в вектор

    std::cout << "Number to find:  ";
    int el;
    std::cin >> el;
    auto it = std::find(vector.begin(), vector.end(), el); //сохраняется в переменную it с использованием ключевого слова auto. auto дает вывести тип на основе типа возвращаемого значения 
    if (it != vector.end()) {
        int index = std::distance(vector.begin(), it);
        std::cout << "Index" << el << " in the end: " << index << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    vector.erase(std::unique(vector.begin(), vector.end()), vector.end()); // Удаляем повторяющиеся

    std::cout << "New vector: ";
    for (int elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    inputFile.close();
    return 0;
}