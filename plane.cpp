#include "plane.h"


Plane::Plane() : name(""),  type(""), volume(0), dimensions(), cities() {
    cout << "Использован конструктор без параметров для объекта Plane\n";
}

Plane::Plane(const string& n, const string& t, const float& v, Dimensions& d, Cities& c) : 
    name(n), type(t), volume(v), dimensions(d), cities(c) {
    cout << "Использован конструктор с параметрами для объекта Plane\n";
}

Plane::Plane(const Plane& other) : name(other.name), type(other.type), volume(other.volume), dimensions(other.dimensions), cities(other.cities) {
    cout << "Использован конструктор копирования для объекта Plane\n";
}

Plane::~Plane() {
    cout << "Использован деструктор для объекта Plane\n";
}

void Plane::set_name(string n) {
    this->name = n;
}

string Plane::get_name() {
    return this->name;
}

void Plane::set_type(string t) {
    this->type = t;
}

string Plane::get_type() {
    return this->type;
}

void Plane::set_volume(float v) {
    this->volume = v;
}

float Plane::get_volume() {
    return this->volume;
}

void Plane::set_dimensions(Dimensions d) {
    this->dimensions = d;
}

Dimensions Plane::get_dimensions() {
    return this->dimensions;
}

void Plane::set_cities(Cities c) {
    this->cities = c;
}

Cities Plane::get_cities() {
    return this->cities;
}

void Plane::display() {
    cout << "Название самолета: " << this->name << endl;
    cout << "Тип самолета: " << this->type << endl;
    cout << "Объем самолета: " << this->volume << endl;
    cout << "Габариты самолета: ";
    this->dimensions.display_demensions();
    cout << endl;
    cout << "Список городов: ";
    this->cities.display_cities();
    cout << endl;
}

void Plane::change_info() {
    int choice;
    string newName, newType;
    float newVolume;
    Dimensions newDimensions;
    Cities newCities;

    cout << "Выберите информацию для изменения:" << endl;
    cout << "1. Название" << endl;
    cout << "2. Тип" << endl;
    cout << "3. Объем" << endl;
    cout << "4. Габариты" << endl;
    cout << "5. Список городов" << endl;
    cout << "0. Выход" << endl;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Введите новое название: ";
            getline(cin, newName);
            set_name(newName);
            break;
        case 2:
            cout << "Введите новый тип: ";
            getline(cin, newType);
            set_type(newType);
            break;
        case 3:
            cout << "Введите новый объем: ";
            cin >> newVolume;
            set_volume(newVolume);
            break;
        case 4:
            cout << "Введите новые габариты:" << endl;
            newDimensions.input_dimensions();
            set_dimensions(newDimensions);
            break;
        case 5:
            cout << "Введите новый список городов:" << endl;
            newCities.input_cities();
            set_cities(newCities);
            break;
        case 0:
            cout << "Выход из редактирования." << endl;
            break;
        default:
            cout << "Неверный выбор." << endl;
            break;
    }
}

void Plane::save_to_file(ostream& out){
        out << "Plane\n";
        out << name << '\n' << type << '\n' << volume << '\n';
        dimensions.save_to_file(out);
        cities.save_to_file(out);
    }

void Plane::load_from_file(istream& in) {
    getline(in, name);
    getline(in, type);
    in >> volume;
    dimensions.load_from_file(in);
    cities.load_from_file(in);
}