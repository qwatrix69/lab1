#include "cargomover.h"

class Plane: public Cargomover
{
private:
    string name;
    string type;
    float volume;
    float dimensions[3];
    string cities[1];
public:
    Plane();
    Plane(const string& n, const string& t, const float& v, const float* d[3], const string* c[1]);
    Plane(const Plane& other);
    ~Plane();

    void set_value(const string& v);
    void get_value();

    void display();
    void change_values();
};

