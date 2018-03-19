#include<iostream>
#include<thread>

using namespace std;

void threadFn(int &value)
{
    cout<<"I am inside a thread function 1 "<<value<<endl;
    value++;

}

// To compile : g++ MultiThreading.cpp -pthread -std=c++11

int main()
{
    int localvalue = 100;
    thread t1{threadFn, ref(localvalue)};       //we can pass by reference as well this way using ref
    t1.join();          

/*
IMPLEMENTATION of Lambda : 
[](int &value){

    something something something
}
*/

//thread using Lambda instead of a full function

    // thread t2{[](int value){
    // cout<<"I am inside a thread function "<<value<<endl;
    // value++;
    // }, ref(localvalue)};

    thread t2{[&](){                                            //all the local function scope can be accessed by reference
    cout<<"I am inside a thread function 2 "<<localvalue<<endl;
    localvalue++;
    }};

    t2.join();


    thread t3{[=](){                                            //This means that the local function scope can be accessed by value but
    cout<<"I am inside a thread function 3 "<<localvalue<<endl;   //cannot be modified.
    }};

    t3.join();

    cout<<localvalue<<endl;                    ///wait for t1 to complete before we exit main
    return 0;
}




