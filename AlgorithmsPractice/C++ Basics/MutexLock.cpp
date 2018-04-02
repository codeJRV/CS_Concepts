#include<iostream>
#include<string>
#include<thread>
#include<mutex>

std::mutex mu;

using namespace std;

void function_1( string s, int id )
{

    std::lock_guard<std::mutex> guard (mu);           //Std_lock_gurard is a better method than mutex directly - its RAII
    //mu.lock();                                      //thread gets locked forever if there is an exception
    std::cout<<s<<" "<<id<<endl;                      //however even this is not safe, since cout is still accessiblnbne outside 
    //mu.unlock(); 


}

void function_2 ()
{
    int i = 100;
    while (--i)
    function_1(string("from t1"),i );

}

int main()
{

    std::thread t1(function_2);

    int i = 100;
    while (--i)
    function_1(string("from main: "), i);

    t1.join();
    return 0;
}