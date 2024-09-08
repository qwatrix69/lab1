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

    virtual void set_value(const string& v) = 0;
    virtual void get_value() = 0;

    virtual void display() = 0;
};