#pragma once

#include <cstdlib>

#include "cargomover.h"
#include "cities.h"

class Train: public Cargomover
{
private:
    string name;
    int year;
    Cities cities;
    int vans;
    float volume;
public:
    Train();
    Train(const string& n, const int& y, Cities& c, const int& van, const float& v);
    Train(const Train& other);
    ~Train();

    void set_name(string n);
    string get_name();

    void set_year(int y);
    int get_year();

    void set_cities(Cities c);
    Cities get_cities();

    void set_vans(int van);
    int get_vans();
    
    void set_volume(float v);
    float get_volume();

    void display() override;
    void change_info() override;
    void save_to_file(ostream&) override;
    void load_from_file(istream&) override;
};

