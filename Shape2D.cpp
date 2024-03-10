#include "Shape2D.h"

float Shape2D::GetArea() {
    CalculateArea();
    return area;
}

bool Shape2D::operator<(Shape2D &other) {
    return this->GetArea() < other.GetArea();
}

bool Shape2D::operator>(Shape2D &other) {
    return this->GetArea() > other.GetArea();
}

bool Shape2D::operator==(Shape2D &other) {
    return this->GetArea() == other.GetArea();
}
