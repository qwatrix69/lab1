#include "keeper.h"
#include "check.h"

void display_add_menu();

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {cout << "Вызван конструктор без параметров для Keeper класса\n";}

Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {cout << "Вызван конструктор с параметрами для Keeper класса\n";}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Вызван конструктор копирования для Keeper класса\n";
}

Keeper::~Keeper() {
    cout << "Вызван деструктор для Keeper класса\n";
    delete_all();
    }

void Keeper::delete_head() {
    if (head) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
    }
}

void Keeper::delete_all() {
    while (head != 0)
        delete_head();
    
}

void Keeper::display_keeper() {
    Element* temp = head;

    if (count == 0) {
        cout << "Данных нет" << endl;
        return;
    }
    int i = 0;
    while (temp != 0) {
        cout << i + 1 <<" - ";
        if (temp->data) {
            temp->data->display(); 
        } else {
            cout << "Данных нет";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}

int Keeper::get_count() {
    return count;
}

Keeper& Keeper::operator++() {
    int add_choice = -1;
    while (add_choice != 0) {
        display_add_menu();
        add_choice = check_input();

        if (add_choice == 1) {
            string name, type;
            float volume;
            Dimensions dimensions;
            Cities cities;

            cout << "Введите название самолета: ";
            getline(cin, name);
            cout << "Введите тип самолета: ";
            getline(cin, type);
            cout << "Введите объем груза: ";
            volume = check_input();
            dimensions.input_dimensions();
            cin.ignore();
            cities.input_cities();
            Plane* plane = new Plane(name, type, volume, dimensions, cities);
            add_to_start(plane);
        }
        else if (add_choice == 2) {
            string name;
            int year, vans;
            Cities cities;
            float volume;

            cout << "Введите название поезда: ";
            getline(cin, name);
            cout << "Введите год выпуска: ";
            year = check_input();
            cout << "Введите полный маршрут. ";
            cities.input_cities();
            cout << "Введите количество вагонов: ";
            vans = check_input();
            cout << "Введите объем груза: ";
            volume = check_input();

            Train* train = new Train(name, year, cities, vans, volume);
            add_to_start(train);
        }
        else if (add_choice == 3) {
            int year;
            string name, firm, model;
            Cities cities;
            float volume;

            cout << "Введите название автомобиля: ";
            getline(cin, name);
            cout << "Введите год выпуска: ";
            year = check_input();
            cout << "Введите марку автомобиля: ";
            getline(cin, firm);
            cout << "Введите модель автомобиля: ";
            getline(cin, model);
            cout << "Введите объем груза: ";
            volume = check_input();
            cout << "Введите полный маршрут. ";
            cities.input_cities();

            Car* car = new Car(name, year, firm, model, cities, volume);
            add_to_start(car);
        }
        else if (add_choice == 0) {
            break;
        }
        else {
            cout << "Введите корректное значение" << endl;
            continue;
        }
    }
    return *this;
}


Keeper& operator++(Keeper& K, int) {
    int add_choice = -1;
    while (add_choice != 0) {
        display_add_menu();
        add_choice = check_input();

        if (add_choice == 1) {
            string name, type;
            float volume;
            Dimensions dimensions;
            Cities cities;

            cout << "Введите название самолета: ";
            getline(cin, name);
            cout << "Введите тип самолета: ";
            getline(cin, type);
            cout << "Введите объем груза: ";
            volume = check_input();
            dimensions.input_dimensions();
            cities.input_cities();

            Plane* plane = new Plane(name, type, volume, dimensions, cities);
            K.add(plane);
        }
        else if (add_choice == 2) {
            string name;
            int year, vans;
            Cities cities;
            float volume;

            cout << "Введите название поезда: ";
            getline(cin, name);
            cout << "Введите год выпуска: ";
            year = check_input();
            cout << "Введите полный маршрут. ";
            cities.input_cities();
            cout << "Введите количество вагонов: ";
            vans = check_input();
            cout << "Введите объем груза: ";
            volume = check_input();

            Train* train = new Train(name, year, cities, vans, volume);
            K.add(train);
        }
        else if (add_choice == 3) {
            int year;
            string name, firm, model;
            Cities cities;
            float volume;

            cout << "Введите название автомобиля: ";
            getline(cin, name);
            cout << "Введите год выпуска: ";
            year = check_input();
            cout << "Введите марку автомобиля: ";
            getline(cin, firm);
            cout << "Введите модель автомобиля: ";
            getline(cin, model);
            cout << "Введите объем груза: ";
            volume  = check_input();
            cout << "Введите полный маршрут. ";
            cities.input_cities();

            Car* car = new Car(name, year, firm, model, cities, volume);
            K.add(car);
        }
        else if (add_choice == 0) {
            break;
        }
        else {
            cout << "Введите корректное значение" << endl;
            continue;
        }
    }
    return K;
}

Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "Данных нет. Невозможно удалить с начала" << endl;
        return K;
    }
    
    Element* temp = K.head;
    K.head = K.head->next;

    delete temp->data;
    delete temp;
    K.count--;

    if (K.count == 0) {
        K.tail = nullptr;
    }

    return K;
}

Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "Данных нет. Невозможно удалить с конца" << endl;
        return *this;
    }

    if (this->count == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    } else {
        Element* temp = this->head;
        while (temp->next != this->tail) {
            temp = temp->next;
        }
        delete this->tail->data;
        delete this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }

    this->count--;
    return *this;
}

Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }

    if (n == 1) {
        this->operator--(0); 
        return *this;
    }

    Element* temp = head;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }

    Element* toDelete = temp->next;
    temp->next = toDelete->next;

    if (toDelete == tail) {
        tail = temp;
    }

    delete toDelete->data;
    delete toDelete;
    count--;

    return *this;
}

Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }

    Element* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }

    if (temp->data) {
        cout << "Данные изменены для элемента с индексом" << n << endl;
        temp->data->change_info(); 
    } else {
        cout << "Данных нет" << endl;
    }

    return *this;
}

Element* Keeper::get_head() {
    return this->head;
}

Element* Keeper::get_tail() {
    return this->tail;
}

void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save_to_file(out);
        current = current->next;
    }
    out.close();
}

void Keeper::load_from_file(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Ошибка открытия файла для загрузки!" << endl;
        return;
    }

    string marker;
    while (getline(in, marker)) {
        if (!marker.empty() && marker.back() == '\r') {
            marker.pop_back();
        }

        Cargomover* mover = nullptr;

    
        if (marker == "Plane") {
            mover = new Plane();
        } else if (marker == "Train") {
            mover = new Train();
        } else if (marker == "Car") {
            mover = new Car();
        } else {
            cerr << "Неизвестный тип объекта: " << marker << endl;
            continue; 
        }

        if (mover) {
            mover->load_from_file(in);
            cout << "Объект добавлен в контейнер" << endl;
            this->add(mover);
        }
    }

    in.close();
}

void Keeper::add(Cargomover* mover) {
    Element* newElement = new Element;
    newElement->data = mover; 
    newElement->next = nullptr;

    if (head == nullptr) {
        head = tail = newElement;
    } else {
        tail->next = newElement;
        tail = newElement;
    }
    
    count++;
}

void Keeper::add_to_start(Cargomover* mover) {
    Element* newElement = new Element;
    newElement->data = mover;
    newElement->next = head; 

    if (head == nullptr) {
        tail = newElement;
    }

    head = newElement; 
    count++;
}

void display_add_menu() {
    cout << "\n--- Добавить транспорт ---" << endl;
    cout << "1. Добавить самолет" << endl;
    cout << "2. Добавить поезд" << endl;
    cout << "3. Добавить автомобиль" << endl;
    cout << "0. Вернуться в главное меню" << endl;
    cout << "Выберите тип транспорта: ";
}