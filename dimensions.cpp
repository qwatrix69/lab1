#include "dimensions.h"

Dimensions::Dimensions() : length(0), width(0), height(0) {}

Dimensions::Dimensions(float& l, float& w, float& h) : length(l), width(w), height(h) {}

Dimensions::Dimensions(const Dimensions& other) : length(other.length), width(other.width), height(other.height) {}

Dimensions::~Dimensions() {}
    
void Dimensions::display_demensions() {
    cout << "Длина" << this->length << endl;
    cout << "Ширина" << this->width << endl;
    cout << "высота" << this->height << endl;
}

void Dimensions::input_dimensions() {
    cout << "Введите длину: ";
    cin >> length;
    
    cout << "Введите ширину: ";
    cin >> width;
    
    cout << "Введите высоту: ";
    cin >> height;
}