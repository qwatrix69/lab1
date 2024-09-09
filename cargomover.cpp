#include "cargomover.h"

Cargomover::Cargomover() : name("") {}

Cargomover::Cargomover(const string& n) : name(n) {}

Cargomover::Cargomover(const Cargomover& other) : name(other.name) {}

Cargomover::~Cargomover() {}

