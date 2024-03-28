#include <iostream>
#include <cstdlib>
#include <ctime>

class Matrix {
private:
    int** data; 
    unsigned int m; 
    unsigned int n;

public:

    Matrix(unsigned int m, unsigned int n): m(m), n(n) {
        data = new int*[m]; 
        for (unsigned int i = 0; i < m; i++) {
            data[i] = new int[n]; 

        }
    }

    Matrix(const Matrix& other): m(other.m), n(other.n) {
        data = new int*[m];
        for (unsigned int i = 0; i < m; i++) {
            data[i] = new int[n];
            for (unsigned int j = 0; j < n; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

// Деструктор памяти
    ~Matrix() {
        for (unsigned int i = 0; i < m; i++) {
            delete[] data[i]; 
        }
        delete[] data;
    }

    int* operator[](unsigned int index) {
        return data[index];
    }

    void fillRandom() {
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                data[i][j] = rand() % 10;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (unsigned int i = 0; i < matrix.m; i++) {
            for (unsigned int j = 0; j < matrix.n; j++) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix& operator+=(const Matrix& other) {
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& other) {
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& other) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < other.n; j++) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix& other) {
        if (m != other.m || n != other.n) {
            return false;
        }
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) {
        return !(*this == other);
    }
};

int main() {
    Matrix A(3, 3);
    A.fillRandom();
    Matrix B = A;

    std::cout << "Matrix A:" << std::endl;
    std::cout << A << std::endl;
    std::cout << "Matrix B:" << std::endl;
    std::cout << B << std::endl;

    Matrix C = A + B;
    std::cout << "Matrix C = A + B:" << std::endl;
    std::cout << C << std::endl;

    C -= A;
    std::cout << "Matrix C -= A:" << std::endl;
    std::cout << C << std::endl;

    Matrix D = A * B;
    std::cout << "Matrix D = A * B:" << std::endl;
    std::cout << D << std::endl;
  
    if (A == B) {
        std::cout << "Matrix A is equal to B" << std::endl;
    } 
    else {
        std::cout << "Matrix A is not equal to B" << std::endl;
    }

    return 0;
}