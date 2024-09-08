#include <iostream>
#include <string>

using namespace std;

class Base
{
private:
    string name;
public:
    Base();
    Base(const string& n);
    Base(const Base& other);
    virtual ~Base();

    virtual void set_value(const string& v) = 0;
    virtual void get_value() = 0;

    virtual void display() = 0;
};