#include "TriangularPyramid.h"


void TriangularPyramid::CalculateVolume() {
    this->volume = triangle->GetArea() * height / 3;
}

TriangularPyramid::TriangularPyramid(float height, Triangle &triangle) {
    this->triangle = &triangle;
    this->height = height;
}

void TriangularPyramid::Scale(float scaleFactory) {
    this->triangle->Scale(scaleFactory);
    height *= scaleFactory;
}

std::string TriangularPyramid::GetName() {
    return "Треугольная пирамида";
}

void TriangularPyramid::ShowInfo() {
    std::cout << "Я " << GetName() << "!\n\tМой объем = " << GetVolume() << "\n\tВысота = " << height
              << "\n\tВ моем основании лежит треугольник, его hello message:\n\t";
    this->triangle->ShowInfo();
}
