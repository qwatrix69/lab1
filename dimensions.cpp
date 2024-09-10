#include "dimensions.h"

Dimensions::Dimensions() : length(0), width(0), height(0) {}

Dimensions::Dimensions(float& l, float& w, float& h) : length(l), width(w), height(h) {}

Dimensions::Dimensions(const Dimensions& other) : length(other.length), width(other.width), height(other.height) {}

Dimensions::~Dimensions() {}
    
void Dimensions::display_demensions() {
    cout << "Длина: " << this->length << endl;
    cout << "Ширина: " << this->width << endl;
    cout << "Высота: " << this->height;
}

void Dimensions::input_dimensions() {
    cout << "Введите длину: ";
    while (!(cin >> length)) {
        cin.clear();
        cin.ignore();
        cout << "Некорректный ввод. Введите длину: ";
    }

    cout << "Введите ширину: ";
    while (!(cin >> width)) {
        cin.clear();
        cin.ignore();
        cout << "Некорректный ввод. Введите ширину: ";
    }

    cout << "Введите высоту: ";
    while (!(cin >> height)) {
        cin.clear();
        cin.ignore();
        cout << "Некорректный ввод. Введите высоту: ";
    }
}

void Dimensions::save_to_file(ostream& out) const{
    out << width << ' ' << height << ' ' << length << '\n';
}

void Dimensions::load_from_file(istream& in) {
    in >> width >> height >> length;
}