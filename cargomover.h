#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cargomover
{
private:
    string name;
public:
    Cargomover();
    Cargomover(const string& n);
    Cargomover(const Cargomover& other);
    virtual ~Cargomover();

    virtual void display() = 0;
    virtual void change_info() = 0;
    virtual void save_to_file(ostream&) = 0;
    virtual void load_from_file(istream&) = 0;
};
