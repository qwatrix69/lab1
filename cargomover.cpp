#include "cargomover.h"

Cargomover::Cargomover() {cout << "Вызван конструктор без параметров для Base класса\n";}

Cargomover::Cargomover(const string& n) {cout << "Вызван конструктор с параметрами для Base класса\n";}

Cargomover::Cargomover(const Cargomover& other) {cout << "Вызван конструктор копирования для Base класса\n";}

Cargomover::~Cargomover() {cout << "Вызван виртуальный деструктор для Base класса\n";}
