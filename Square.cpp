#include "Square.h"

Square::Square(float side) {
    this->side = side;
}

void Square::ShowInfo() {
    std::cout << "Я " << GetName() << "!\n\tМоя площадь = " << GetArea() << "\n\tДлина стороны = " << side << std::endl;
}

std::string Square::GetName() {
    return "треугольник";
}

void Square::CalculateArea() {
    this->area = side * side;
}

void Square::Scale(float scaleFactor) {
    this->side *= scaleFactor;
}
