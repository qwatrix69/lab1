#include "cities.h"

Cities::Cities() : cities(nullptr), size(0), capacity(0) {}

Cities::Cities(int& c) : size(c), capacity(c) {
    cities = (char**)calloc(c, sizeof(char*));
        if (!cities) {
            cerr << "Ошибка выделения памяти!" << std::endl;
            exit(1);
        }
}

Cities::Cities(const Cities& other) : size(other.size), capacity(other.capacity) {
    cities = (char**)calloc(capacity, sizeof(char*));
    if (!cities) {
        cerr << "Ошибка выделения памяти при копировании!" << endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        cities[i] = (char*)malloc((strlen(other.cities[i]) + 1) * sizeof(char));
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
    char** new_cities = (char**)realloc(cities, new_capacity * sizeof(char*));
    if (!new_cities) {
        cerr << "Ошибка выделения памяти при изменении размера!" << endl;
        exit(1);
    }

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
    cities = (char**)calloc(capacity, sizeof(char*));
    if (!cities) {
        cerr << "Ошибка выделения памяти!" << endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        cities[i] = (char*)malloc((strlen(other.cities[i]) + 1) * sizeof(char));
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

    cities[size] = (char*)malloc((strlen(c) + 1) * sizeof(char));
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
    for (int i = 0; i < size; ++i) {
        free(cities[i]);
    }
    free(cities);   
    cities = nullptr;
    size = 0;
    capacity = 0;
}

void Cities::input_cities() {
    clear_cities();  

    int num_cities;
    cout << "Введите количество городов для добавления: ";
    cin >> num_cities;
    cin.ignore();

    for (int i = 0; i < num_cities; ++i) {
        char buffer[100];
        cout << "Введите название города #" << (i + 1) << ": ";
        cin.getline(buffer, 100);

        add_city(buffer);
    }
}

void Cities::save_to_file(std::ostream& out) const {
    // Сначала сохраняем размер массива
    out << size << '\n';  
    // Затем сохраняем каждый город
    for (int i = 0; i < size; ++i) {
        out << cities[i] << '\n';  // Записываем строку города
    }
}

void Cities::load_from_file(std::istream& in) {
    // Сначала считываем размер
    in >> size;
    in.ignore();  // Игнорируем символ новой строки

    // Очищаем текущий массив городов, если он был
    clear_cities();

    // Перевыделяем память под города
    capacity = size;
    cities = new char*[capacity];

    // Считываем каждый город
    for (int i = 0; i < size; ++i) {
        std::string city;
        std::getline(in, city);  // Считываем строку города

        // Выделяем память под новую строку
        cities[i] = new char[city.size() + 1];
        std::strcpy(cities[i], city.c_str());  // Копируем строку в массив
    }
}
