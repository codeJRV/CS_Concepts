//
// Created by jrv on 3/18/18.
//

//USING TEMPLATES

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <class T>
class Bucky{
   T first, second;
public:
   Bucky(T a,T b) :
           first(a),second(b){}
   T bigger();
};

template <class T>
T Bucky<T>::bigger(){
   return ((first>second)?first:second);
}

int main()
{
   Bucky<int> bo(69,105);

}