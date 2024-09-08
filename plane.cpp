#include "plane.h"


Plane::Plane() : name(""),  type(""), volume(0), dimensions(), cities() {
    cout << "Использован конструктор без параметров для объекта Plane\n";
}

Plane::Plane(const string& n, const string& t, const float& v, Dimensions& d, Cities& c) : 
    name(n), type(t), volume(v), dimensions(d), cities(c) {}

Plane::Plane(const Plane& other) : name(other.name), type(other.type), volume(other.volume), dimensions(other.dimensions), cities(other.cities) {}

Plane::~Plane() {
    cout << "Использован деструктор для объекта Plane\n";
}

void Plane::set_name() const {

}

void Plane::get_name() const {

}