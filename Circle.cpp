#include "Circle.h"

Circle::Circle(float radius) {
    this->radius = radius;
}

void Circle::Scale(float scaleFactor) {
    this->radius *= scaleFactor;
}

std::string Circle::GetName() {
    return "круг";
}

void Circle::ShowInfo() {
    std::cout << "Я " << GetName() << "!\n\tМоя площадь = " << GetArea() << "\n\tМой радиус = " << radius<<std::endl;
}

void Circle::CalculateArea() {
    this->area = 3.14 * radius * radius;
}
