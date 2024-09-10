#include <iostream>
#include <string>

#include "keeper.h"
#include "plane.h"
#include "train.h"
#include "car.h"

using namespace std;

void display_main_menu() {
    cout << "\n--- Главное меню ---" << endl;
    cout << "1. Добавить новый транспорт в конец" << endl;
    cout << "2. Добавить новый транспорт в начало" << endl;
    cout << "3. Удалить транспорт по индексу" << endl;
    cout << "4. Удалить транспорт c конца" << endl;
    cout << "5. Удалить транспорт c начала" << endl;
    cout << "6. Редактировать транспорт" << endl;
    cout << "7. Отобразить список транспорта" << endl;
    cout << "8. Сохранить данные в файл" << endl;
    cout << "9. Загрузить данные из файла" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

int main() {
    Keeper keeper;
    int choice = -1;

    while (choice != 0) {
        display_main_menu();
        cin >> choice;

        switch (choice) {
            case 1: {
                keeper++;
                break;
            }
            case 2: {
                ++keeper;
                break;
            }
            case 3: {
                int index;
                cout << "Введите номер транспорта для удаления: ";
                cin >> index;
                keeper.delete_element(index); 
                break;
            }
            case 4: {
                keeper--;
                break;
            }
            case 5: {
                --keeper;
                break;
            }
            case 6: {
                int index;
                cout << "Введите номер транспорта для редактирования: ";
                cin >> index;
                keeper.edit_element(index); 
                break;
            }
            case 7:
                keeper.display_keeper(); 
                break;
            case 8:
                keeper.save_to_file("out.csv");
                break;
            case 9:
                keeper.load_from_file("in.csv");
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
