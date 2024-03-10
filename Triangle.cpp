#include "Triangle.h"

Triangle::Triangle(float base, float height) {
    this->base = base;
    this->height = height;
}

std::string Triangle::GetName() {
    return "треугольник";
}

void Triangle::ShowInfo() {
    std::cout << "Я " << GetName() << "!\n\tМоя площадь = " << GetArea() << "\n\tДлина основания = " << base
              << "\n\t Высота = " << height << std::endl;
}

void Triangle::Scale(float scaleFactor) {
    this->height *= scaleFactor;
    this->base *= scaleFactor;
}

void Triangle::CalculateArea() {
    this->area = base * height * 0.5;
}
