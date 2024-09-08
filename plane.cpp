#include "plane.h"


Plane::Plane() : name(""),  type(""), volume(0) {
    dimensions[0] = dimensions[1] = dimensions[2] = 0;
    cities[0] = "";
    cout << "Использован конструктор без параметров";
}

