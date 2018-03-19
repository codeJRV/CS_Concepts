#include<iostream>
#include<cstring>

class Foo
{

public:

// Constructor

Foo():
data( new char[100])
{

std::strcpy(data,"Hello World!");

}

//Copy Constructor
Foo (const Foo& other):
data(new char[std::strlen(other.data)+1])
{
std::strcpy(data,other.data);
std::cout<<"Copy Constructor called\n";
}

//Copy Assignment Operator

Foo& operator= (const Foo& other)
{
    Foo tmp(other);
    *this = std::move(tmp);
    return *this;
    std::cout<<"Copy Assignment operator called\n";


}


private:
char * data;

};