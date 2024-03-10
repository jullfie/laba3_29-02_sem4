#include <iostream>
#include "model/impl/2d/Circle.h"
#include "model/impl/2d/Square.h"
#include "model/impl/2d/Triangle.h"
#include "model/impl/3d/Cylinder.h"
#include "model/impl/3d/Sphere.h"
#include "model/impl/3d/TriangularPyramid.h"

void testCircle() {
    float radius = 2;
    Circle circle(radius);
    std::cout << "Создан круг с радиусом = " << radius << ", проверка до масштабирования\n";
    circle.ShowInfo();
    float scaleFactory = 3;
    circle.Scale(scaleFactory);
    std::cout << "Масштабх" << scaleFactory << ", проверка: ";
    circle.ShowInfo();
}

void testSquare() {
    float side = 2;
    Square square(side);
    std::cout << "Создан квадрат со стороной = " << side << ", проверка до масштабирования\n";
    square.ShowInfo();
    float scaleFactory = 3;
    square.Scale(scaleFactory);
    std::cout << "Масштабх" << scaleFactory << ", проверка: ";
    square.ShowInfo();
}

void testTriangle() {
    float base = 2;
    float height = 3;
    Triangle triangle(base, height);
    std::cout << "Создан треугольник со основанием = " << base << " и высотой = " << height
              << ", проверка до масштабирования\n";
    triangle.ShowInfo();
    float scaleFactory = 3;
    triangle.Scale(scaleFactory);
    std::cout << "Масштабх" << scaleFactory << ", проверка: ";
    triangle.ShowInfo();
}

void testCylinder() {
    float radius = 2;
    float height = 3;
    Circle circle(radius);
    Cylinder cylinder(height, circle);
    std::cout << "Создан цилиндр с радусм основания = " << radius << " и высотой = " << height
              << ", проверка до масштабирования\n";
    cylinder.ShowInfo();
    float scaleFactory = 2;
    cylinder.Scale(scaleFactory);
    std::cout << "Масштабх" << scaleFactory << ", проверка: ";
    cylinder.ShowInfo();
}

void testPyramid() {
    float base = 2;
    float triangleHeight = 3;
    float height = 4;
    Triangle triangle(base, triangleHeight);
    TriangularPyramid triangularPyramid(height, triangle);
    std::cout << "Создана пирамида с основанием треугольника = " << base << ", высотой треугольника = "
              << triangleHeight << " и собственной высотой = " << height
              << ", проверка до масштабирования\n";
    triangularPyramid.ShowInfo();
    float scaleFactory = 2;
    triangularPyramid.Scale(scaleFactory);
    std::cout << "Масштабх" << scaleFactory << ", проверка: ";
    triangularPyramid.ShowInfo();
}

void testSphere() {
    float radius = 2;
    Sphere sphere(radius);
    std::cout << "Создана сфера с радиусом = " << radius << ", проверка до масштабирования\n";
    sphere.ShowInfo();
    float scaleFactory = 3;
    sphere.Scale(scaleFactory);
    std::cout << "Масштабх" << scaleFactory << ", проверка: ";
    sphere.ShowInfo();
}

int main() {
    std::cout << "\nТЕСТ КРУГА\n";
    testCircle();
    std::cout << "\nТЕСТ КВАДРАТА\n";
    testSquare();
    std::cout << "\nТЕСТ ТРЕУГОЛЬНИКА\n";
    testTriangle();
    std::cout << "\nТЕСТ СФЕРЫ\n";
    testSphere();
    std::cout << "\nТЕСТ ЦИЛИНДРА\n";
    testCylinder();
    std::cout << "\nТЕСТ ПИРАМИДЫ\n";
    testPyramid();
}
