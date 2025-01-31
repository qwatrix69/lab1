#include "train.h"
#include "check.h"

Train::Train() : name(""), year(0), cities(), vans(0), volume(0) {cout << "Вызван конструктор без параметров для Train класса\n";}

Train::Train(const string& n, const int& y, Cities& c, const int& van, const float& v) : name(n), year(y), cities(c), vans(van), volume(v) {
    cout << "Вызван конструктор c параметрами для Train класса\n";
}

Train::Train(const Train& other) : name(other.name), year(other.year), cities(other.cities), vans(other.vans), volume(other.volume) {
    cout << "Вызван конструктор копирования для Train класса\n";
}

Train::~Train() {cout << "Вызван деструктор для Train класса\n";}

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
    cout << "Маршрут следования: " << endl;
    this->cities.display_cities();
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
    choice = check_input();

    switch (choice) {
        case 1:
            cout << "Введите новое название: " << endl;
            getline(cin, newName);
            set_name(newName);
            cout << "Данные успешно изменены" << endl;
            break;
        case 2:
            cout << "Введите новый год выпуска: " << endl;
            newYear = check_input();
            set_year(newYear);
            cout << "Данные успешно изменены" << endl;
            break;
        case 3:
            cout << "Введите новый маршрут следования" << endl;
            newCities.input_cities();
            set_cities(newCities);
            cout << "Данные успешно изменены" << endl;
            break;
        case 4:
            cout << "Введите новое количество вагонов: " << endl;
            newVans = check_input();
            set_vans(newVans);
            cout << "Данные успешно изменены" << endl;
            break;
        case 5:
            cout << "Введите новый объем: " << endl;
            newVolume = check_input();
            set_volume(newVolume);
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

void Train::save_to_file(ostream& out) {
    out << "Train\n";
    out << name << '\n' << year << '\n';
    cities.save_to_file(out);
    out << vans << '\n' << volume << '\n';
}

void Train::load_from_file(istream& in) {
    getline(in, name);
    in >> year;
    cities.load_from_file(in);
    in >> vans >> volume;
}