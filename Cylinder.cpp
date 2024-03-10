
#include "Cylinder.h"

Cylinder::Cylinder(float height, Circle &circle) {
    this->height = height;
    this->circle = &circle;
}

void Cylinder::CalculateVolume() {
    this->volume = this->circle->GetArea() * height;
}

void Cylinder::Scale(float scaleFactory) {
    this->circle->Scale(scaleFactory);
    this->height *= scaleFactory;
}

std::string Cylinder::GetName() {
    return "цилиндр";
}

void Cylinder::ShowInfo() {
    std::cout << "Я " << GetName() << "!\n\tМой объем = " << GetVolume() << "\n\tВысота = " << height
              << "\n\tВ моем основании лежит круг, его hello message:\n\t";
    this->circle->ShowInfo();
}
