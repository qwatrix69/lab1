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
};