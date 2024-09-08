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

    virtual void set_name() = 0;
    virtual void get_name() = 0;

    virtual void display() = 0;
    virtual void change_info() = 0;
    virtual void save_to_file() = 0;
    virtual void load_to_file() = 0;
};