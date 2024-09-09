#include <iostream>
#include <string>
#include "keeper.h"
#include "plane.h"
#include "train.h"
#include "car.h"

using namespace std;

void display_main_menu() {
    cout << "\n--- Главное меню ---" << endl;
    cout << "1. Добавить новый транспорт" << endl;
    cout << "2. Удалить транспорт" << endl;
    cout << "3. Редактировать транспорт" << endl;
    cout << "4. Отобразить список транспорта" << endl;
    cout << "5. Сохранить данные в файл" << endl;
    cout << "6. Загрузить данные из файла" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

void display_add_menu() {
    cout << "\n--- Добавить транспорт ---" << endl;
    cout << "1. Добавить самолет" << endl;
    cout << "2. Добавить поезд" << endl;
    cout << "3. Добавить автомобиль" << endl;
    cout << "0. Вернуться в главное меню" << endl;
    cout << "Выберите тип транспорта: ";
}

int main() {
    Keeper keeper;  // Инициализация контейнера
    int choice = -1;

    while (choice != 0) {
        display_main_menu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int add_choice = -1;
                while (add_choice != 0) {
                    display_add_menu();
                    cin >> add_choice;
                    cin.ignore(); // Игнорируем символ новой строки после выбора

                    if (add_choice == 1) {  // Добавление самолета
                        string name, type;
                        float volume;
                        Dimensions dimensions;
                        Cities cities;

                        cout << "Введите название самолета: ";
                        getline(cin, name);
                        cout << "Введите тип самолета: ";
                        getline(cin, type);
                        cout << "Введите объем груза: ";
                        cin >> volume;
                        cin.ignore(); // Игнорируем символ новой строки

                        dimensions.input_dimensions();  // Ввод габаритов
                        cities.input_cities();          // Ввод городов

                        Plane* plane = new Plane(name, type, volume, dimensions, cities);
                        keeper++; // Добавляем объект в контейнер
                        keeper.get_tail()->data = plane;
                    }
                    else if (add_choice == 2) {  // Добавление поезда
                        string name;
                        int year;
                        Cities cities;
                        int vans;
                        float volume;

                        cout << "Введите название поезда: ";
                        getline(cin, name);
                        cout << "Введите год выпуска: ";
                        cin >> year;
                        cin.ignore(); // Игнорируем символ новой строки
                        cout << "Введите полный маршрут: ";
                        cities.input_cities();
                        cout << "Введите количество вагонов: ";
                        cin >> vans;
                        cout << "Введите объем груза: ";
                        cin >> volume;
                        cin.ignore(); // Игнорируем символ новой строки

                        Train* train = new Train(name, year, cities, vans, volume);
                        keeper++; // Добавляем объект в контейнер
                        keeper.get_tail()->data = train;
                    }
                    else if (add_choice == 3) {  // Добавление автомобиля
                        int year;
                        string name, firm, model;
                        Cities cities;
                        float volume;

                        cout << "Введите название автомобиля: ";
                        getline(cin, name);
                        cout << "Введите год выпуска: ";
                        cin >> year;
                        cin.ignore(); // Игнорируем символ новой строки
                        cout << "Введите марку автомобиля: ";
                        getline(cin, firm);
                        cout << "Введите модель автомобиля: ";
                        getline(cin, model);
                        cout << "Введите объем груза: ";
                        cin >> volume;
                        cin.ignore(); // Игнорируем символ новой строки

                        cities.input_cities();  // Ввод городов

                        Car* car = new Car(name, year, firm, model, cities, volume);
                        keeper++; // Добавляем объект в контейнер
                        keeper.get_tail()->data = car;
                    }
                }
                break;
            }
            case 2: {
                int index;
                cout << "Введите номер транспорта для удаления: ";
                cin >> index;
                keeper.delete_element(index);  // Удаление элемента
                break;
            }
            case 3: {
                int index;
                cout << "Введите номер транспорта для редактирования: ";
                cin >> index;
                keeper.edit_element(index);  // Редактирование элемента
                break;
            }
            case 4:
                keeper.display_keeper();  // Отображение списка транспорта
                break;
            case 5:
                // keeper.refresh(keeper);  // Сохранение в файл
                break;
            case 6:
                // keeper.recovery(keeper);  // Загрузка из файла
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
    }

    return 0;
}
