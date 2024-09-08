#include "dimensions.h"

Dimensions::Dimensions() : length(0), width(0), height(0) {}

Dimensions::Dimensions(float& l, float& w, float& h) : length(l), width(w), height(h) {}

Dimensions::Dimensions(const Dimensions& other) : length(other.length), width(other.width), height(other.height) {}

Dimensions::~Dimensions() {}