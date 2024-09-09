#include <string>
#include <iostream>
#pragma once
using namespace std;

class Dimensions
{
private:
    float length;
    float width;
    float height;
public:
    Dimensions();
    Dimensions(float& l, float& w, float& h);
    Dimensions(const Dimensions& other);
    ~Dimensions();

    void display_demensions();
    void input_dimensions();
    
    void save_to_file(ostream& out) const;
    void load_from_file(istream& in);

};