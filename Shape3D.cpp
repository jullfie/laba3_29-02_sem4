#include "Shape3D.h"

float Shape3D::GetVolume() {
    CalculateVolume();
    return volume;
}

bool Shape3D::operator>(Shape3D &other) {
    return this->GetVolume() > other.GetVolume();
}

bool Shape3D::operator<(Shape3D &other) {
    return this->GetVolume() < other.GetVolume();
}

bool Shape3D::operator==(Shape3D &other) {
    return this->GetVolume() == other.GetVolume();
}
