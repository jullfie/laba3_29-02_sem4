#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>

// Шаблонный класс Matrix для работы с матрицами различных типов данных
template <typename T>
class Matrix {
private:
    unsigned int rows; // Количество строк в матрице
    unsigned int cols; // Количество столбцов в матрице
    T** elements; // Указатель на массив элементов матрицы

public:
    // Конструктор с параметрами для инициализации матрицы
    Matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
        elements = new T * [rows]; // Выделение памяти для строк
        for (unsigned int i = 0; i < rows; ++i) {
            elements[i] = new T[cols]; // Выделение памяти для столбцов
        }
    }

    // Деструктор для освобождения выделенной памяти
    ~Matrix() {
        for (unsigned int i = 0; i < rows; ++i) {
            delete[] elements[i]; // Освобождение памяти для столбцов каждой строки
        }
        delete[] elements; // Освобождение памяти для строк
    }

    // Доступ к элементам матрицы с проверкой выхода за границы
    T& at(unsigned int row, unsigned int col) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return elements[row][col];
    }

    // Получение количества строк
    unsigned int getRows() const { return rows; }
    // Получение количества столбцов
    unsigned int getCols() const { return cols; }

    // Заполнение матрицы случайными числами
    void fillRandom() {
        static bool seeded = false;
        if (!seeded) {
            srand(time(nullptr)); // Инициализация генератора случайных чисел
            seeded = true;
        }
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                elements[i][j] = static_cast<T>(rand() % 100); // Генерация случайного числа
            }
        }
    }

    // Перегрузка оператора вывода для печати матрицы
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (unsigned int i = 0; i < matrix.rows; ++i) {
            for (unsigned int j = 0; j < matrix.cols; ++j) {
                os << std::setw(8) << matrix.elements[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // Оператор сложения матриц
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices dimensions must match for addition.");
        }
        Matrix result(rows, cols);
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }

    // Оператор вычитания матриц
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices dimensions must match for subtraction.");
        }
        Matrix result(rows, cols);
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                result.elements[i][j] = elements[i][j] - other.elements[i][j];
            }
        }
        return result;
    }

    // Оператор умножения матриц
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("The number of columns in the first matrix must equal the number of rows in the second matrix.");
        }
        Matrix result(rows, other.cols);
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < other.cols; ++j) {
                result.elements[i][j] = static_cast<T>(0);
                for (unsigned int k = 0; k < cols; ++k) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }

    // Оператор присваивания для копирования матрицы
    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this; // Проверка на самоприсваивание

        // Освобождение текущей памяти матрицы
        for (unsigned int i = 0; i < rows; ++i) {
            delete[] elements[i];
        }
        delete[] elements;

        // Выделение памяти для новой матрицы и копирование элементов
        rows = other.rows;
        cols = other.cols;
        elements = new T * [rows];
        for (unsigned int i = 0; i < rows; ++i) {
            elements[i] = new T[cols];
            for (unsigned int j = 0; j < cols; ++j) {
                elements[i][j] = other.elements[i][j];
            }
        }
        return *this;
    }

    // Метод для заполнения матрицы одним и тем же значением
    void fill(T value) {
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                elements[i][j] = value;
            }
        }
    }
};

#endif // MATRIX_H
