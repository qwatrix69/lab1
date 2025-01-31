#include "plane.h"
#include "check.h"

Plane::Plane() : name(""),  type(""), volume(0), dimensions(), cities() {
    cout << "Вызван конструктор без параметров для Plane класса\n";
}

Plane::Plane(const string& n, const string& t, const float& v, Dimensions& d, Cities& c) : 
    name(n), type(t), volume(v), dimensions(d), cities(c) {
    cout << "Вызван конструктор c параметрами для Plane класса\n";
}

Plane::Plane(const Plane& other) : name(other.name), type(other.type), volume(other.volume), dimensions(other.dimensions), cities(other.cities) {
    cout << "Вызван конструктор копирования для Plane класса\n";
}

Plane::~Plane() {
    cout << "Вызван деструктор для Plane класса\n";
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
    cout << "Габариты самолета: " << endl;
    this->dimensions.display_demensions();
    cout << endl;
    cout << "Список городов: " << endl;
    this->cities.display_cities();
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
    choice = check_input();

    switch (choice) {
        case 1:
            cout << "Введите новое название: ";
            getline(cin, newName);
            set_name(newName);
            cout << "Данные успешно изменены" << endl;
            break;
        case 2:
            cout << "Введите новый тип: ";
            getline(cin, newType);
            set_type(newType);
            cout << "Данные успешно изменены" << endl;
            break;
        case 3:
            cout << "Введите новый объем: ";
            newVolume = check_input();
            set_volume(newVolume);
            cout << "Данные успешно изменены" << endl;
            break;
        case 4:
            cout << "Введите новые габариты:" << endl;
            newDimensions.input_dimensions();
            set_dimensions(newDimensions);
            cout << "Данные успешно изменены" << endl;
            break;
        case 5:
            cout << "Введите новый список городов:" << endl;
            newCities.input_cities();
            set_cities(newCities);
            cout << "Данные успешно изменены" << endl;
            break;
        case 0:
            cout << "Выход из редактирования" << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова" << endl;
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