#include <iostream>
#include <string>
#include "cargomover.h"
#include "plane.h"
#include "car.h"
#include "train.h"
#include "dimensions.h"
#include "cities.h"
#pragma once
using namespace std;

struct Element {
    Element* next;
    Cargomover* data;
};

class Keeper
{
private:
    Element* head;
    Element* tail;
    int count;

    void recovery(Keeper& K);
    void refresh(Keeper& K);
    Keeper& read_plane(Keeper& K2);
    Keeper& read_car(Keeper& K2);
    Keeper& read_train(Keeper& K2);

public:
    Keeper();
    Keeper(Element* h, Element* t, int c);
    Keeper(Keeper& other);
    ~Keeper();

    void delete_head();
    void delete_all();
    void display_keeper();
    int get_count();
    Element* get_tail();

    Keeper& operator++(); // в конец добавить
    friend Keeper& operator--(Keeper& K); // Удаление с конца
    friend Keeper& operator++(Keeper& K, int); // в начало
    Keeper& operator--(int); // удаление из начала

    Keeper& delete_element(int n);
    Keeper& edit_element(int n);



};
