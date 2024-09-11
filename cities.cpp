#include "cities.h"

Cities::Cities() : cities(nullptr), size(0), capacity(0) {}

Cities::Cities(int& c) : size(c), capacity(c) {
    cities = new char*[c];
    if (!cities) {
        cerr << "Ошибка выделения памяти!" << endl;
        exit(1);
    }
}

Cities::Cities(const Cities& other) : size(other.size), capacity(other.capacity) {
    cities = new char*[capacity];
    if (!cities) {
        cerr << "Ошибка выделения памяти при копировании!" << endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        cities[i] = new char[strlen(other.cities[i]) + 1];
        if (!cities[i]) {
            cerr << "Ошибка выделения памяти для города!" << endl;
            exit(1);
        }
        strcpy(cities[i], other.cities[i]);
    }
}

Cities::~Cities() {
    clear_cities();
}

void Cities::resize() {
    int new_capacity = (capacity == 0) ? 1 : capacity * 2;
    char** new_cities = new char*[new_capacity];
    if (!new_cities) {
        cerr << "Ошибка выделения памяти при изменении размера!" << endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        new_cities[i] = cities[i];
    }

    delete[] cities;

    cities = new_cities;
    capacity = new_capacity;
}

Cities& Cities::operator=(const Cities& other) {
    if (this == &other) {
        return *this; 
    }

    clear_cities();

    size = other.size;
    capacity = other.capacity;
    cities = new char*[capacity];
    if (!cities) {
        cerr << "Ошибка выделения памяти!" << endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        cities[i] = new char[strlen(other.cities[i]) + 1];
        if (!cities[i]) {
            cerr << "Ошибка выделения памяти для города!" << endl;
            exit(1);
        }
        strcpy(cities[i], other.cities[i]);
    }

    return *this;
}

void Cities::add_city(const char* c) {
    if (size == capacity) {
        resize();
    }

    cities[size] = new char[strlen(c) + 1];
    if (!cities[size]) {
        cerr << "Ошибка выделения памяти для нового города!" << endl;
        exit(1);
    }
    strcpy(cities[size], c);
    ++size;
}

void Cities::display_cities() {
    for (int i = 0; i < size; ++i) {
        cout << (i + 1) << ". " << cities[i] << endl;
    }
}

void Cities::clear_cities() {
    if (cities) {
        for (int i = 0; i < size; ++i) {
            delete[] cities[i];
        }
        delete[] cities;
        cities = nullptr;
    }
    size = 0;
    capacity = 0;
}

void Cities::input_cities() {
    clear_cities();  

    int num_cities;
    cout << "Введите количество городов: ";
    cin >> num_cities;
    cin.ignore();

    for (int i = 0; i < num_cities; ++i) {
        string city;
        cout << "Введите название города #" << (i + 1) << ": ";
        getline(cin, city);

        add_city(city.c_str());
    }
}

void Cities::save_to_file(ostream& out) const {
    out << size << '\n';  
    for (int i = 0; i < size; ++i) {
        out << cities[i] << '\n';
    }
}

void Cities::load_from_file(istream& in) {
    if (!in) {
        cerr << "Ошибка открытия потока для чтения!" << endl;
        return;
    }

    clear_cities();  

    int num_cities;
    in >> num_cities;
    in.ignore();

    for (int i = 0; i < num_cities + 1; ++i) {
        string city;
        if (getline(in, city)) {
            if (!city.empty()) {
                add_city(city.c_str());
            } else {
                continue;
            }
        } else {
            cerr << "Ошибка при чтении города" << endl;
        }
    }
}
