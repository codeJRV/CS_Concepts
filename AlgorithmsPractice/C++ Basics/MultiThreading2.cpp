#include<iostream>
#include<thread>
#include<string>
#include<initializer_list>

using namespace std;

template<typename Type>
void threadFn()
{
    cout<<"I am inside a thread function 1 "<<endl;
    cout<<this_thread::get_id()<<endl;
    cout<<"Type is :"<<typeid(Type).name()<<endl;

}

// To compile : g++ MultiThreading.cpp -pthread -std=c++11

int main()
{
    int localvalue = 100;
    thread t1{threadFn<int>};                                   //implicit conversion does not happen
    this_thread::sleep_for(chrono::milliseconds(1000)); 
    thread t2{threadFn<float>};
    t2.join();
    t1.join();      //we can delay execution of threads this way

return 0;
}




