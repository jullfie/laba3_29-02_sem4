#include "Sphere.h"

Sphere::Sphere(float radius) {
    this->radius = radius;
}

void Sphere::CalculateVolume() {
    this->volume = 4 * 3.14 * radius * radius;
}

std::string Sphere::GetName() {
    return "сфера";
}

void Sphere::Scale(float scaleFactory) {
    this->radius *= scaleFactory;
}

void Sphere::ShowInfo() {
    std::cout << "Я " << GetName() << "!\n\tМой объем = " << GetVolume() << "\n\tРадиус = " << radius << std::endl;
}
