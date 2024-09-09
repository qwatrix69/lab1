#include "keeper.h"

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {}

Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {}

Keeper::~Keeper() {delete_all();}

void Keeper::delete_head() {
    Element* temp = head;
    head = head->next;
    delete temp;
}

void Keeper::delete_all() {
    while (head != 0)
        delete_head();
    
}

void Keeper::display_keeper() {
    Element* temp = head;

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;
    int i = 0;
    while (temp != 0) {
        cout << i + 1 <<" - ";
        if (temp->data) {  // Проверяем, инициализирован ли объект
            temp->data->display(); 
        } else {
            cout << "Empty data";
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
    Element* newElement = new Element;
    newElement->data = nullptr;
    newElement->next = nullptr;

    if (tail == nullptr) {
        head = tail = newElement;
    } else {
        tail->next = newElement;
        tail = newElement;
    }
    
    count++;
    return *this;
}


Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "The list is empty. Cannot delete from the end." << endl;
        return K;
    }

    if (K.count == 1) {
        delete K.head;
        K.head = K.tail = nullptr;
    } else {
        Element* temp = K.head;
        while (temp->next != K.tail) {
            temp = temp->next;
        }
        delete K.tail;
        K.tail = temp;
        K.tail->next = nullptr;
    }

    K.count--;
    return K;
}

Keeper& operator++(Keeper& K, int) {
    Element* newElement = new Element;
    newElement->data = nullptr;
    newElement->next = K.head;
    
    K.head = newElement;
    if (K.count == 0) {
        K.tail = K.head;
    }

    K.count++;
    return K;
}

Keeper& Keeper::operator--(int) {
    if (count == 0) {
        cout << "The list is empty. Cannot delete from the beginning." << endl;
        return *this;
    }

    Element* temp = head;
    head = head->next;

    delete temp;
    count--;

    if (count == 0) {
        tail = nullptr;
    }

    return *this;
}

Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        std::cout << "Invalid index." << std::endl;
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

    delete toDelete;
    count--;

    return *this;
}

Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        std::cout << "Invalid index." << std::endl;
        return *this;
    }

    Element* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }

    if (temp->data) {
        std::cout << "Editing element at position " << n << std::endl;
        temp->data->change_info(); 
    } else {
        std::cout << "Empty data, nothing to edit." << std::endl;
    }

    return *this;
}

Element* Keeper::get_tail() {
    return this->tail;
}