#include "train.h"

Train::Train() : name(""), year(0), cities(), vans(0), volume(0) {}

Train::Train(const string& n, const int& y, Cities& c, const int& van, const float& v) : name(n), year(y), cities(c), vans(van), volume(v) {}

Train::Train(const Train& other) : name(other.name), year(other.year), cities(other.cities), vans(other.vans), volume(other.volume) {}

Train::~Train() {}

void Train::set_name(string n) {
    this->name = n;
}

string Train::get_name() {
    return this->name;
}

void Train::set_year(int y) {
    this->year = y;
}

int Train::get_year() {
    return this->year;
}

void Train::set_cities(Cities c) {
    this->cities = c;
}

Cities Train::get_cities() {
    return this->cities;
}

void Train::set_vans(int van) {
    this->vans = van;
}

int Train::get_vans() {
    return this->vans;
}

void Train::set_volume(float v) {
    this->volume = v;
}

float Train::get_volume() {
    return this->volume;
}

void Train::display() {
    cout << "Название поезда: " << this->name << endl;
    cout << "Год выпуска: " << this->year << endl;
    cout << "Маршрут следования: ";
    this->cities.display_cities();
    cout << endl;
    cout << "Количество поездов: " << this->vans << endl;
    cout << "Объем груза: " << this->volume << endl;
}

void Train::change_info() {
    int choice, newYear, newVans;
    string newName;
    float newVolume;
    Cities newCities;

    cout << "Выберите информацию для изменения:" << endl;
    cout << "1. Название" << endl;
    cout << "2. Год выпуска" << endl;
    cout << "3. Маршрут следования" << endl;
    cout << "4. Количество вагонов" << endl;
    cout << "5. Объем груза" << endl;
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
            cout << "Введите новый год выпуска: ";
            cin >> newYear;
            set_year(newYear);
            break;
        case 3:
            cout << "Введите новый маршрут следования" << endl;
            newCities.input_cities();
            set_cities(newCities);
            break;
        case 4:
            cout << "Введите новое количество вагонов: ";
            cin >> newVans;
            set_vans(newVans);
            break;
        case 5:
            cout << "Введите новый объем: ";
            cin >> newVolume;
            set_volume(newVolume);
            break;
        case 0:
            cout << "Выход из редактирования." << endl;
            break;
        default:
            cout << "Неверный выбор." << endl;
            break;
    }
}