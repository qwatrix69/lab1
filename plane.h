#pragma once

#include <cstdlib>

#include "cargomover.h"
#include "dimensions.h"
#include "cities.h"

class Plane: public Cargomover
{
private:
    string name;
    string type;
    float volume;
    Dimensions dimensions;
    Cities cities;
public:
    Plane();
    Plane(const string& n, const string& t, const float& v, Dimensions& d, Cities& c);
    Plane(const Plane& other);
    ~Plane();

    void set_name(string n);
    string get_name();

    void set_type(string t);
    string get_type();

    void set_volume(float v);
    float get_volume();
    
    void set_dimensions(Dimensions d);
    Dimensions get_dimensions();

    void set_cities(Cities c);
    Cities get_cities();

    void display() override;
    void change_info() override;
    void save_to_file(ostream&) override;
    void load_from_file(istream&) override;
};

