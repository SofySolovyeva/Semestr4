#include <iostream>

template <typename T>
int findSecondMax(T* arr, int size) {
    int maxIndex = 0;
    int secondMaxIndex = -1;

    if (size < 2) {
        return -1;
    }
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            secondMaxIndex = maxIndex;
            maxIndex = i;
        } else if (secondMaxIndex == -1 || arr[i] > arr[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }    
    return secondMaxIndex;
}

template <typename T>
class Matrix {
private:
    int rows;
    int cols;
    T** data;
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    T& operator()(int row, int col) {
        return data[row][col];
    }
};

template <typename T>
class Vector {
private:
    int size;
    T* data;
public:
    Vector(int size) : size(size) {
        data = new T[size];
    }

    ~Vector() {
        delete[] data;
    }

    T& operator[](int index) {
        return data[index];
    }

    T dotProduct(Vector<T>& other) {
        T result = 0;
        for (int i = 0; i < size; i++) {
            result += data[i] * other[i];
        }
        return result;
    }

    T scalarProduct(Vector<T>& other) {
        return dotProduct(other);
    }
};

void testik() {
    int intArr[] = {6, 2, 5, 4, 3};
    float floatArr[] = {6.7, 3.4, 7.2, 5.6, 2.3};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    
    std::cout << "Индекс второго макс элемента в  int : " << findSecondMax(intArr, 5) << std::endl;
    std::cout << "Индекс второго макс элемента в float : " << findSecondMax(floatArr, 5) << std::endl;
    std::cout << "Индекс второго макс элемента в char : " << findSecondMax(charArr, 5) << std::endl;

    Matrix<float> mat(3, 2);
    mat(0, 0) = 6.7;
    mat(0, 1) = 3.4;
    mat(1, 0) = 7.2;
    mat(1, 1) = 5.6;
    mat(2, 0) = 2.3;
    mat(2, 1) = 5.9;
    
    std::cout << mat(1, 0) << std::endl;

    Vector<int> vec1(3);
    Vector<int> vec2(3);
    vec1[0] = 6;
    vec1[1] = 2;
    vec1[2] = 5;
    vec2[0] = 4;
    vec2[1] = 3;
    vec2[2] = 3;

    std::cout << "Вектороное произведение: " << vec1.dotProduct(vec2) << std::endl;
    std::cout << "Скалярное произведение: " << vec1.scalarProduct(vec2) << std::endl;
}

int main() {
    testik();
    return 0;
}