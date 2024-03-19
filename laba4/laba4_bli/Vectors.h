#pragma once
#pragma once
#include "MatrixwithPattern.h" // Включение определения базового класса Matrix для наследования

// Шаблонный класс Vector, специализированный для работы с векторами на основе Matrix
template<typename T>
class Vector : public Matrix<T> {
public:
    // Конструктор инициализирует вектор заданной длины
    Vector(unsigned int length) : Matrix<T>(1, length) {}

    // Скалярное произведение двух векторов
    T dotProduct(const Vector& other) const {
        if (this->getCols() != other.getCols()) {
            throw std::invalid_argument("Vectors must be of the same dimension.");
        }
        T product = 0;
        for (unsigned int i = 0; i < this->getCols(); ++i) {
            product += this->at(0, i) * other.at(0, i);
        }
        return product;
    }

    // Векторное произведение, определено только для трехмерных векторов
    Vector crossProduct(const Vector& other) const {
        if (this->getCols() != 3 || other.getCols() != 3) {
            throw std::invalid_argument("Cross product is defined for 3D vectors only.");
        }

        Vector<T> result(3);
        // Вычисление компонент результата векторного произведения
        result.at(0, 0) = this->at(0, 1) * other.at(0, 2) - this->at(0, 2) * other.at(0, 1);
        result.at(0, 1) = this->at(0, 2) * other.at(0, 1) - this->at(0, 1) * other.at(0, 2);
        result.at(0, 2) = this->at(0, 0) * other.at(0, 1) - this->at(0, 1) * other.at(0, 0);
        return result;
    }
};
