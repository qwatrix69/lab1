#include "car.h"

Car::Car() : name(""), year(0), firm(""), model(""), cities(), volume(0) {cout << "Вызван конструктор без параметров для Car класса\n";}

Car::Car(const string& n, const int& y, const string& f, const string& m, Cities& c, const float& v) : 
name(n), year(y), firm(f), model(m), cities(c), volume(v) {cout << "Вызван конструктор с параметрами для Car класса\n";}

Car::Car(const Car& other) : name(other.name), year(other.year), firm(other.firm), model(other.model), cities(other.cities), volume(other.volume) {
    cout << "Вызван конструктор копирования для Car класса\n";
}

Car::~Car() {cout << "Вызван деструктор  для Car класса\n";}

void Car::set_name(string n) {
    this->name = n;
}

string Car::get_name() {
    return this->name;
}

void Car::set_year(int y) {
    this->year = y;
}

int Car::get_year() {
    return this->year;
}

void Car::set_firm(string f) {
    this->firm = f;
}

string Car::get_firm() {
    return this->firm;
}

void Car::set_model(string m) {
    this->model = m;
}

string Car::get_model() {
    return this->model;
}

void Car::set_cities(Cities c) {
    this->cities = c;
}

Cities Car::get_cities() {
    return this->cities;
}

void Car::set_volume(float v) {
    this->volume = v;
}

float Car::get_volume() {
    return this->volume;
}

void Car::display() {
    cout << "Название машины: " << this->name << endl;
    cout << "Год выпуска: " << this->year << endl;
    cout << "Название марки: " << this->name << endl;
    cout << "Название модели: " << this->year << endl;
    cout << "Маршрут следования: " << endl;
    this->cities.display_cities();
    cout << "Объем груза: " << this->volume << endl;
}

void Car::change_info() {
    int choice, newYear;
    string newName, newFirm, newModel;
    float newVolume;
    Cities newCities;

    cout << "Выберите информацию для изменения:" << endl;
    cout << "1. Название" << endl;
    cout << "2. Год выпуска" << endl;
    cout << "3. Название марки" << endl;
    cout << "4. Название модели" << endl;
    cout << "5. Маршрут следования" << endl;
    cout << "6. Объем груза" << endl;
    cout << "0. Выход" << endl;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            cout << "Введите новое название: " << endl;
            getline(cin, newName);
            set_name(newName);
            break;
        case 2:
            cout << "Введите новый год выпуска: " << endl;
            cin >> newYear;
            set_year(newYear);
            break;
        case 3:
            cout << "Введите новое название марки: " << endl;
            getline(cin, newFirm);
            set_name(newFirm);
            break;
        case 4:
            cout << "Введите новое название модели: " << endl;
            getline(cin, newModel);
            set_name(newModel);
            break;
        case 5:
            cout << "Введите новый маршрут следования" << endl;
            newCities.input_cities();
            set_cities(newCities);
            break;
        case 6:
            cout << "Введите новый объем: " << endl;
            cin >> newVolume;
            set_volume(newVolume);
            break;
        case 0:
            cout << "Выход из редактирования." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
    }
}

void Car::save_to_file(ostream& out) {
    out << "Train\n";
    out << name << '\n' << year << '\n' << firm << '\n' << model << '\n';
    cities.save_to_file(out);
    out << volume << '\n';
}

void Car::load_from_file(istream& in) {
    getline(in, name);
    in >> year >> firm >> model;
    cities.load_from_file(in);
    in >> volume;
}