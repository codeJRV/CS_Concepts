#include<iostream>

using namespace std;

class Point{

    public:

    static Point rectangular(float x, float y);
    static Point polar(float r, float c);

    private:
    Point (float x, float y);
    float x_, y_ ;

};

inline Point::Point(float x, float y)
: x_(x), y_(y){
    cout<<"constructor called\n";
}

inline Point Point::rectangular(float x, float y)
{
    cout<<"rectangular called\n";
    return Point(x,y);
}


inline Point Point::polar(float r, float c)
{
    cout<<"polar called\n";
    return Point(r*r,c*c);
}

int main()
{
    Point p1 = Point::rectangular(1.2,2.4);
    Point p2 = Point::polar(1.2,2.4);
}