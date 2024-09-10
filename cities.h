#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Cities
{
private:
    char** cities;
    int size;
    int capacity;
public:
    Cities();
    Cities(int& c);
    Cities(const Cities& other);
    ~Cities();

    void resize();
    void add_city(const char* c);
    void display_cities();
    void clear_cities();
    void input_cities();

    Cities& operator=(const Cities& other);

    void save_to_file(ostream& out) const;
    void load_from_file(istream& in);

};

