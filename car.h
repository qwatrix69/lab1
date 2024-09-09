#include "cargomover.h"
#include "cities.h"
#include <cstdlib>
#pragma once
class Car: public Cargomover
{
private:
    string name;
    int year;
    string firm;
    string model;
    Cities cities;
    float volume;
public:
    Car();
    Car(const string& n, const int& y, const string& f, const string& m, Cities& c, const float& v);
    Car(const Car& other);
    ~Car();

    void set_name(string n);
    string get_name();

    void set_year(int y);
    int get_year();

    void set_firm(string f);
    string get_firm();

    void set_model(string m);
    string get_model();
    
    void set_cities(Cities c);
    Cities get_cities();

    void set_volume(float v);
    float get_volume();

    void display() override;
    void change_info() override;
    //void save_to_file() override;
    // void load_to_file() override;
};

