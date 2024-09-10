#include "cargomover.h"

Cargomover::Cargomover() : name("") {cout << "Вызван конструктор без параметров для Base класса\n";}

Cargomover::Cargomover(const string& n) : name(n) {cout << "Вызван конструктор с параметрами для Base класса\n";}

Cargomover::Cargomover(const Cargomover& other) : name(other.name) {cout << "Вызван конструктор копирования для Base класса\n";}

Cargomover::~Cargomover() {cout << "Вызван виртуальный деструктор для Base класса\n";}
