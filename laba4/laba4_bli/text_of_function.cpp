#include <iostream>
#include "findSecondMaximum.h"
#include "MatrixwithPattern.h"
#include "Vectors.h"

int main() {
    // Установка локали для корректного отображения кириллицы в консоли
    std::setlocale(LC_ALL, "Russian");


    // тесты 2 максимума
    std::cout << "\n--- Second Maximum Tests ---\n";
    // Демонстрация поиска второго максимального элемента в массивах различных типов
    int intArray[] = { 1, 3, 5, 2, 4 };
    std::cout << "Index of the second maximum in the int array: " << findSecondMaximum(intArray, sizeof(intArray) / sizeof(intArray[0])) << std::endl;

    float floatArray[] = { 1.1f, 3.3f, 5.5f, 2.2f, 4.4f };
    std::cout << "Index of the second maximum in the float array: " << findSecondMaximum(floatArray, sizeof(floatArray) / sizeof(floatArray[0])) << std::endl;

    double doubleArray[] = { 1.01, 3.03, 5.05, 2.02, 4.04 };
    std::cout << "Index of the second maximum in the double array: " << findSecondMaximum(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0])) << std::endl;

    char charArray[] = { 'a', 'e', 'i', 'o', 'u' };
    std::cout << "Index of the second maximum in the char array: " << findSecondMaximum(charArray, sizeof(charArray) / sizeof(charArray[0])) << std::endl;



    // Создание и демонстрация работы с матрицами разных типов
    std::cout << "\n--- Matrix Tests ---\n";

    // Создание матрицы целых чисел 3x3 и её заполнение случайными значениями
    Matrix<int> intMatrix(3, 3);
    intMatrix.fillRandom();
    std::cout << "Int Matrix (random):\n" << intMatrix << std::endl;

    // Создание матрицы с плавающей точкой 3x3 и её заполнение случайными значениями
    Matrix<float> floatMatrix(3, 3);
    floatMatrix.fillRandom();
    std::cout << "Float Matrix (random):\n" << floatMatrix << std::endl;

    // Создание и заполнение матрицы двойной точности 2x2 нулями, затем изменение конкретных элементов
    Matrix<double> doubleMatrix(2, 2);
    doubleMatrix.fillZeros();
    doubleMatrix.at(0, 0) = 1.5;
    doubleMatrix.at(1, 1) = 2.5;
    std::cout << "Double Matrix (manual):\n" << doubleMatrix << std::endl;

    // Демонстрация операций сложения и вычитания матриц
    Matrix<int> sumMatrix = intMatrix + intMatrix; // Сложение матрицы с самой собой
    std::cout << "Sum of int matrices:\n" << sumMatrix << std::endl;

    Matrix<float> diffMatrix = floatMatrix - floatMatrix; // Вычитание матрицы из самой себя
    std::cout << "Difference of float matrices:\n" << diffMatrix << std::endl;

    // Создание двух матриц для демонстрации умножения
    Matrix<int> matrixA(2, 3); // Матрица 2x3
    Matrix<int> matrixB(3, 2); // Матрица 3x2, совместимая с matrixA для умножения

    // Заполнение матриц A и B случайными значениями
    matrixA.fillRandom();
    matrixB.fillRandom();

    std::cout << "Matrix A (2x3):\n" << matrixA << std::endl;
    std::cout << "Matrix B (3x2):\n" << matrixB << std::endl;

    // Выполнение умножения матриц
    Matrix<int> productMatrix = matrixA * matrixB; // Результатом будет матрица 2x2
    std::cout << "Product of Matrix A and Matrix B:\n" << productMatrix << std::endl;



    // Тестирование операций с векторами
    std::cout << "\n--- Vector Tests ---\n";

    // Создание двух трехмерных векторов для демонстрации скалярного и векторного произведения
    Vector<int> vector1(3); // Первый вектор
    Vector<int> vector2(3); // Второй вектор

    // Инициализация векторов
    vector1.at(0, 0) = 1; vector1.at(0, 1) = 2; vector1.at(0, 2) = 3;
    vector2.at(0, 0) = 4; vector2.at(0, 1) = 5; vector2.at(0, 2) = 6;

    std::cout << "Vector 1: (1, 2, 3)\n";
    std::cout << "Vector 2: (4, 5, 6)\n";

    // Выполнение и вывод скалярного произведения векторов
    int dotProductResult = vector1.dotProduct(vector2);
    std::cout << "Dot product of Vector 1 and Vector 2: " << dotProductResult << std::endl;

    // Выполнение и вывод векторного произведения (только для трехмерных векторов)
    if (vector1.getCols() == 3 && vector2.getCols() == 3) {
        Vector<int> crossProductResult = vector1.crossProduct(vector2);
        std::cout << "Cross product of Vector 1 and Vector 2: ("
            << crossProductResult.at(0, 0) << ", "
            << crossProductResult.at(0, 1) << ", "
            << crossProductResult.at(0, 2) << ")" << std::endl;
    }
    else {
        std::cout << "Cross product is defined for 3D vectors only." << std::endl;
    }

    return 0;
}
