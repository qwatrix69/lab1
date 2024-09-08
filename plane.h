#include "cargomover.h"
#include "dimensions.h"
#include "cities.h"
#include "dimensions.h"
#include <cstdlib>

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

    void set_name() const;
    void get_name() const;

    void set_type() const;
    void get_type() const;

    void set_volume() const;
    void get_volume() const;
    
    void set_dimensions() const;
    void get_dimensions() const;

    void set_cities() const;
    void get_cities() const;

    void display() override;
    void change_info() override;
    void save_to_file() override;
    void load_to_file() override;
};

